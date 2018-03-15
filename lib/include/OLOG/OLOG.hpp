#ifndef OLOG_HPP
#define OLOG_HPP

#define OLOG_ERROR 0
#define OLOG_WARNING 1
#define OLOG_INFO 2
#define OLOG_FAILURE 3

#include "OLOG/Log.hpp"

namespace OLOG {
    Log* init_log(const char* name, const char* file);

    Log* get_log_by_name(const char* name);
}

#endif // OLOG_HPP