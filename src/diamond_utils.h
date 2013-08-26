#ifndef DIAMOND_UTILS_H
#define DIAMOND_UTILS_H

namespace DIAMOND_NS {
std::string toString(legacy_db_type dbType);
handlerton *getHandlerton(legacy_db_type dbType);
}

#endif // DIAMOND_UTILS_H
