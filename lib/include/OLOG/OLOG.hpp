#ifndef OLOG_HPP
#define OLOG_HPP


#include "OLOG/Log.hpp"

namespace OLOG {

    Log* init_log(const char* name, const char* file);

    Log* get_log_by_name(const char* name);
}

#endif // OLOG_HPP
