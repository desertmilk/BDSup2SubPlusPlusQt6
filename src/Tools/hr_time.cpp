#include "hr_time.h"

#include <chrono>

CStopWatch::CStopWatch()
{
    startTime = std::chrono::steady_clock::time_point{};
    stopTime = std::chrono::steady_clock::time_point{};
}

void CStopWatch::startTimer()
{
    startTime = std::chrono::steady_clock::now();
}

void CStopWatch::stopTimer()
{
    stopTime = std::chrono::steady_clock::now();
}

double CStopWatch::getElapsedTime()
{
    const auto elapsed = std::chrono::duration<double>(stopTime - startTime);
    return elapsed.count();
}
