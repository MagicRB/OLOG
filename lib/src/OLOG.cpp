#include "OLOG/OLOG.hpp"

#include <map>

#include <iostream>

std::map<char*, OLOG::Log> log_map;

OLOG::Log* OLOG::init_log(char* name, char *file) {
    log_map[name] = Log();

    log_map.at(name).log_file = new std::ofstream(file);

    return &log_map.at(name);
}

OLOG::Log *OLOG::get_log_by_name(char *name) {
    return &log_map.at(name);
}
