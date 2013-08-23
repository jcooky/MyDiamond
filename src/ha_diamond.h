
#ifndef HA_DIAMOND_H_
#define HA_DIAMOND_H_

#include "handler.h"

namespace DIAMOND_NS {
class ha_diamond : public handler {
public:
	static handler *create(legacy_db_type dbType, handlerton *hton, TABLE_SHARE *table, MEM_ROOT *mem_root);

	ha_diamond(handlerton *hton, TABLE_SHARE *tableShare);

	virtual Table_flags table_flags(void) const;
	virtual const char **bas_ext() const;
	virtual int info(uint);
	virtual int open(const char *name, int mode, uint test_if_locked);
	virtual int create(const char *name, TABLE *form, HA_CREATE_INFO *info);
	virtual THR_LOCK_DATA **store_lock(THD *thd,
					   THR_LOCK_DATA **to,
					   enum thr_lock_type lock_type);
	virtual ulong index_flags(uint idx, uint part, bool all_parts) const;
	virtual int rnd_pos(uchar * buf, uchar *pos);
	virtual int rnd_init(bool scan);
	virtual void position(const uchar *record);
	virtual int rnd_next(uchar *buf);
	virtual const char *table_type() const;
	virtual int close();

private:
	handler *innerHandler;
};

}

#endif /* HA_DIAMOND_H_ */
