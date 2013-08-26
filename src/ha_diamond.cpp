
#include "diamond.h"

namespace DIAMOND_NS {

handler *ha_diamond::create(legacy_db_type dbType, handlerton *hton, TABLE_SHARE *table, MEM_ROOT *mem_root) {
	LEX_STRING handler_name;
	handlerton *new_hton = getHandlerton(dbType);

	handler *innerHandler = get_new_handler(table, mem_root, new_hton);
	if (innerHandler == NULL)
	{
		return NULL;
	}

	innerHandler->ht = new_hton;
	ha_diamond* handler = new (mem_root) ha_diamond(hton, table);

	handler->innerHandler = innerHandler;

	return handler;
}

ha_diamond::ha_diamond(handlerton *hton, TABLE_SHARE *tableShare)
: handler(hton, tableShare) {
}

handler::Table_flags ha_diamond::table_flags(void) const {

}

const char **ha_diamond::bas_ext() const {

}

int ha_diamond::info(uint) {

}

int ha_diamond::open(const char *name, int mode, uint test_if_locked) {

}

int ha_diamond::create(const char *name, TABLE *form, HA_CREATE_INFO *info) {

}

THR_LOCK_DATA **ha_diamond::store_lock(THD *thd, THR_LOCK_DATA **to, enum thr_lock_type lock_type) {

}

ulong ha_diamond::index_flags(uint idx, uint part, bool all_parts) const {

}

int ha_diamond::rnd_pos(uchar * buf, uchar *pos) {

}

int ha_diamond::rnd_init(bool scan) {

}

void ha_diamond::position(const uchar *record) {

}

int ha_diamond::rnd_next(uchar *buf) {

}

const char *ha_diamond::table_type() const {

}

int ha_diamond::close() {

}

}
