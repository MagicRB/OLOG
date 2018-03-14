#include "OLOG/OLOG.hpp"

#include <iostream>

int main()
{
    OLOG::init_log("main", "stdout");
    OLOG::Log* log = OLOG::get_log_by_name("main");

    log->log(OLOG_ERROR, "main.cpp", "Test Error");
    log->log(OLOG_WARNING, "main.cpp", "Test Warning");
    log->log(OLOG_INFO, "main.cpp", "Test Info");
    log->log(OLOG_FAILURE, "main.cpp", "Test Failure");

    log->close();

    return 0;
}