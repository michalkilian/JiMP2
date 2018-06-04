//
// Created by Michał on 2018-06-04.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <iostream>

namespace profiling {
    template<class T>
    auto TimeRecorder(T Function) {
        std::chrono::time_point<std::chrono::system_clock> startTimer, stopTimer;
        startTimer = std::chrono::system_clock::now();
        Function();
        stopTimer = std::chrono::system_clock::now();
        std::chrono::duration<double> time = (stopTimer - startTimer);
        return std::pair<decltype(Function()), double> {Function(), time.count() * 1000.f};
    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
