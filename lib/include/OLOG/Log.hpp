//
// Created by Magic_RB on 3/13/18.
//

#ifndef OLOG_LOG_HPP
#define OLOG_LOG_HPP

#include <fstream>

namespace OLOG {

    enum MessageType {

        error = 0,
        warning = 1,
        info = 2,
        failure = 3


    };

    enum LogType {

        file = 0,
        stdout = 1,
        both = 2

    };

    class Log {
    public:
        Log();
        ~Log();

        std::ofstream* log_file;
        int status = 0;
        LogType type = file;

        long int message_number = 0;

        int get_status();

        void log(OLOG::MessageType message_type, const char* issuer, const char* text);

        void close();

    protected:

    private:

    };
}

#endif //OLOG_LOG_HPP
