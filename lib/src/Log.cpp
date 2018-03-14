//
// Created by Magic_RB on 3/13/18.
//

#include <chrono>
#include <iomanip>
#include <iostream>

#include "OLOG/Log.hpp"
#include "OLOG/OLOG.hpp"

OLOG::Log::Log() {

}

OLOG::Log::~Log() {

}

void OLOG::Log::log(int message_type, char *issuer, char *text) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);

    char* type_c;

    switch(message_type) {
        case OLOG_ERROR: {
            type_c = "Error";
            break;
        }
        case OLOG_WARNING: {
            type_c = "Warning";
            break;
        }
        case OLOG_INFO: {
            type_c = "Info";
            break;
        }
        case OLOG_FAILURE: {
            type_c = "Failure";
            status = OLOG_FAILURE;
            break;
        }
        default: {
            type_c = "Undefined";
            break;
        }
    }

    if (type == 0) {
        *log_file << "{" << message_number << "}[" << std::put_time(std::localtime(&now_c), "%T") << "](" << issuer << ") " << type_c << ": " << text << "\n";
    }
    if (type == 1) {
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
