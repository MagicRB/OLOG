//
// Created by Magic_RB on 3/13/18.
//

#ifndef OLOG_LOG_HPP
#define OLOG_LOG_HPP

#include <fstream>

namespace OLOG {
    class Log {
    public:
        Log();
        ~Log();

        std::ofstream* log_file;
        int status = 0;

        int get_status();

        void log(int type, char* issuer, char* text);

        void close();

        long int message_number = 0;

    protected:

    private:

    };
}

#endif //OLOG_LOG_HPP
