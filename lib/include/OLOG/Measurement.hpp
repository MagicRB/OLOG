//
// Created by main on 3/15/18.
//

#ifndef OLOG_MEASUREMENT_HPP
#define OLOG_MEASUREMENT_HPP

#include <string>
#include <chrono>

namespace OLOG {
    class Measurement {
    public:
        Measurement();
        ~Measurement();

        void start();
        void end();
        long report();
        std::string report_string();
    protected:

        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;

    private:

    };
}

#endif //OLOG_MEASUREMENT_HPP
