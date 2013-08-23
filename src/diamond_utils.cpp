#include "diamond.h"

namespace DIAMOND_NS {

std::string toString(legacy_db_type dbType) {
    switch(dbType) {
    case DB_TYPE_MYISAM: return "MyISAM";
    case DB_TYPE_INNODB: return "InnoDB";
    }

    return "";
}

handlerton *getHandlerton(legacy_db_type dbType) {
	LEX_STRING handler_name;
	std::string storageName = toString(dbType);

	handler_name.str = const_cast<char *>(storageName.c_str());
	handler_name.length = storageName.length();

#if MYSQL_VERSION_ID < 50600
	plugin_ref plugin = ha_resolve_by_name(current_thd, &handler_name);
#else
	plugin_ref plugin = ha_resolve_by_name(current_thd, &handler_name, false);
#endif
	if (plugin == NULL)
	{
		return NULL;
	}
	return plugin_data(plugin, handlerton *);
}

}
