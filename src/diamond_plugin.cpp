
#include "diamond.h"

struct st_mysql_storage_engine diamond_storage_engine = { MYSQL_HANDLERTON_INTERFACE_VERSION };

namespace DIAMOND_NS {
static handler *createHandlerMyisam(handlerton *hton, TABLE_SHARE *table, MEM_ROOT *mem_root) {
	return ha_diamond::create(DB_TYPE_MYISAM, hton, table, mem_root);
}

static handler *createHandlerInnodb(handlerton *hton, TABLE_SHARE *table, MEM_ROOT *mem_root) {
	return ha_diamond::create(DB_TYPE_INNODB, hton, table, mem_root);
}

static int initMyisam(void *p)
{
	handlerton *hton = (handlerton *) p;

	hton->state = SHOW_OPTION_YES;
	hton->create = createHandlerMyisam;
	hton->flags = HTON_CAN_RECREATE | HTON_SUPPORT_LOG_TABLES;

	return 0;
}

static int initInnodb(void *p)
{
	handlerton *hton = (handlerton *) p;

	hton->state = SHOW_OPTION_YES;
	hton->create = createHandlerInnodb;
	hton->flags = HTON_NO_FLAGS;

	return 0;
}

static int finalize(void *p)
{
	return 0;
}

}

maria_declare_plugin(diamond)
{
MYSQL_STORAGE_ENGINE_PLUGIN,
&diamond_storage_engine,
"diamond_myisam",
"MyDiamond",
"MyDiamond Storage Engine",
PLUGIN_LICENSE_BSD,
DIAMOND_NS::initMyisam, /* Plugin Init */
DIAMOND_NS::finalize, /* Plugin Deinit */
0x000001 /* 0.1 */,
NULL, /* status variables */
NULL, /* system variables */
"0.0.1", /* string version */
MariaDB_PLUGIN_MATURITY_EXPERIMENTAL /* maturity */
},
{
MYSQL_STORAGE_ENGINE_PLUGIN,
&diamond_storage_engine,
"diamond_innodb",
"D'Amo, Penta Security",
"DAmo storage engine",
PLUGIN_LICENSE_BSD,
DIAMOND_NS::initInnodb, /* Plugin Init */
DIAMOND_NS::finalize, /* Plugin Deinit */
0x000001 /* 0.0.1 */,
NULL, /* status variables */
NULL, /* system variables */
"0.0.1", /* string version */
MariaDB_PLUGIN_MATURITY_EXPERIMENTAL /* maturity */
}
maria_declare_plugin_end;
