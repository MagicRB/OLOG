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

    log->type = OLOG::LogType::both;

    measure.start();

    log->log(OLOG::MessageType::error, "main.cpp", "Test Error");
    log->log(OLOG::MessageType::warning, "main.cpp", "Test Warning");
    log->log(OLOG::MessageType::info, "main.cpp", "Test Info");
    log->log(OLOG::MessageType::failure, "main.cpp", "Test Failure");

    measure.end();

    log->log(OLOG::MessageType::info, "main.cpp", ((std::string)"Logging took " + measure.report_string() + (std::string)" us. ").c_str());

    log->log(OLOG::MessageType::info, "main.cpp", "If you're seeing this message the test passed successfully, congrats!");

    main_measure.end();

    log->log(OLOG::MessageType::info, "main.cpp", ((std::string)"The whole main function took " + main_measure.report_string() + (std::string)" us to run!").c_str());

    log->close();

    return 0;
}
