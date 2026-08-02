#ifndef HR_TIME_H
#define HR_TIME_H

#include <chrono>

class CStopWatch {
private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point stopTime;

public:
    CStopWatch();
    void startTimer();
    void stopTimer();
    double getElapsedTime();
};

#endif // HR_TIME_H
