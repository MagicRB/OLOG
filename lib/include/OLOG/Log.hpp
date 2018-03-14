//
// Created by Magic_RB on 3/13/18.
//

#ifndef OLOG_LOG_HPP
#define OLOG_LOG_HPP

#define OLOG_LOG_FILE 0
#define OLOG_LOG_STDOUT 1

#include <fstream>

namespace OLOG {

    class Log {
    public:
        Log();
        ~Log();

        std::ofstream* log_file;
        int status = 0;
        int type = 0;
        long int message_number = 0;

        int get_status();

        void log(int message_type, char* issuer, char* text);

        void close();

    protected:

    private:

    };
}

#endif //OLOG_LOG_HPP
