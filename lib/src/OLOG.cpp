#include "OLOG/OLOG.hpp"

#include <map>

#include <iostream>

std::map<const char*, OLOG::Log> log_map;

OLOG::Log* OLOG::init_log(const char* name, const char *file) {
    log_map[name] = Log();

    log_map.at(name).log_file = new std::ofstream(file);

    return &log_map.at(name);
}

OLOG::Log *OLOG::get_log_by_name(const char *name) {
    return &log_map.at(name);
}
