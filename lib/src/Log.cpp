//
// Created by Magic_RB on 3/13/18.
//

#include <chrono>
#include <iomanip>
#include <iostream>

#include "OLOG/Log.hpp"
#include "OLOG/OLOG.hpp"

OLOG::Log::Log() = default;

OLOG::Log::~Log() = default;

void OLOG::Log::log(int message_type, const char *issuer, const char *text) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);

    char* type_c;

    switch(message_type) {
        case OLOG_ERROR: {
            type_c = (char *)"Error";
            break;
        }
        case OLOG_WARNING: {
            type_c = (char *)"Warning";
            break;
        }
        case OLOG_INFO: {
            type_c = (char *)"Info";
            break;
        }
        case OLOG_FAILURE: {
            type_c = (char *)"Failure";
            status = OLOG_FAILURE;
            break;
        }
        default: {
            type_c = (char *)"Undefined";
            break;
        }
    }

    if (type == OLOG_LOG_FILE || type == OLOG_LOG_BOTH) {
        *log_file << "{" << message_number << "}[" << std::put_time(std::localtime(&now_c), "%T") << "](" << issuer << ") " << type_c << ": " << text << "\n";
        log_file->flush();
    }
    if (type == OLOG_LOG_STDOUT || type == OLOG_LOG_BOTH) {
        std::cout << "{" << message_number << "}[" << std::put_time(std::localtime(&now_c), "%T") << "](" << issuer << ") " << type_c << ": " << text << "\n";
    }

    message_number++;
}

void OLOG::Log::close() {
    log_file->close();
}

int OLOG::Log::get_status() {
    return status;
}
