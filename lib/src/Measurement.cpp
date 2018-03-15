//
// Created by main on 3/15/18.
//

#include "OLOG/Measurement.hpp"

OLOG::Measurement::Measurement() = default;

OLOG::Measurement::~Measurement() = default;

void OLOG::Measurement::start() {
    start_time = std::chrono::steady_clock::now();
}

void OLOG::Measurement::end() {
    end_time = std::chrono::steady_clock::now();
}

long OLOG::Measurement::report() {
    return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

std::string OLOG::Measurement::report_string() {
    return std::to_string(report());
}
