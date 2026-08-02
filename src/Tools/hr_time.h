#ifndef HR_TIME_H
#define HR_TIME_H

#ifdef Q_OS_WIN
#include <windows.h>

typedef struct {
        LARGE_INTEGER start;
        LARGE_INTEGER stop;
} stopWatch;
#else
#include <chrono>

typedef struct {
        std::chrono::steady_clock::time_point start;
        std::chrono::steady_clock::time_point stop;
} stopWatch;
#endif

class CStopWatch {

private:
        stopWatch timer;
#ifdef Q_OS_WIN
        LARGE_INTEGER frequency;
        double LIToSecs( LARGE_INTEGER & L);
#endif
public:
        CStopWatch();
        void startTimer( );
        void stopTimer( );
        double getElapsedTime();
};

#endif // HR_TIME_H
