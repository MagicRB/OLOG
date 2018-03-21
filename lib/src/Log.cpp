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

void OLOG::Log::log(OLOG::MessageType message_type, const char *issuer, const char *text) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);

    char* type_c;

    switch(message_type) {
        case OLOG::MessageType::error: {
            type_c = (char *)"Error";
            break;
        }
        case OLOG::MessageType::warning: {
            type_c = (char *)"Warning";
            break;
        }
        case OLOG::MessageType::info: {
            type_c = (char *)"Info";
            break;
        }
        case OLOG::MessageType::failure: {
            type_c = (char *)"Failure";
            status = OLOG::MessageType::failure;
            break;
        }
        default: {
            type_c = (char *)"Undefined";
            break;
        }
    }

    if (type == OLOG::LogType::file || type == OLOG::LogType::both) {
        *log_file << "{" << message_number << "}[" << std::put_time(std::localtime(&now_c), "%T") << "](" << issuer << ") " << type_c << ": " << text << "\n";
        log_file->flush();
    }
    if (type == OLOG::LogType::stdout || type == OLOG::LogType::both) {
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
