#include "OLOG/OLOG.hpp"
#include "OLOG/Measurement.hpp"

#include <iostream>

int main()
{
    OLOG::Measurement main_measure;

    main_measure.start();

    OLOG::init_log("main", "log.log");
    OLOG::Log* log = OLOG::get_log_by_name("main");

    OLOG::Measurement measure;

    log->type = OLOG_LOG_BOTH;

    measure.start();

    log->log(OLOG_ERROR, "main.cpp", "Test Error");
    log->log(OLOG_WARNING, "main.cpp", "Test Warning");
    log->log(OLOG_INFO, "main.cpp", "Test Info");
    log->log(OLOG_FAILURE, "main.cpp", "Test Failure");

    measure.end();

    log->log(OLOG_INFO, "main.cpp", ((std::string)"Logging took " + measure.report_string() + (std::string)" us. ").c_str());

    log->log(OLOG_INFO, "main.cpp", "If you're seeing this message the test passed successfully, congrats!");

    main_measure.end();

    log->log(OLOG_INFO, "main.cpp", ((std::string)"The whole main function took " + main_measure.report_string() + (std::string)" us to run!").c_str());

    log->close();

    return 0;
}