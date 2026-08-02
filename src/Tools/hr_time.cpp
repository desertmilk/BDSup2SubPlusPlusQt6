#include "hr_time.h"

#ifdef Q_OS_WIN

double CStopWatch::LIToSecs( LARGE_INTEGER & L) {
        return ((double)L.QuadPart /(double)frequency.QuadPart);
}

CStopWatch::CStopWatch(){
        timer.start.QuadPart=0;
        timer.stop.QuadPart=0;
        QueryPerformanceFrequency( &frequency );
}

void CStopWatch::startTimer( ) {
    QueryPerformanceCounter(&timer.start);
}

void CStopWatch::stopTimer( ) {
    QueryPerformanceCounter(&timer.stop);
}


double CStopWatch::getElapsedTime() {
        LARGE_INTEGER time;
        time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
    return LIToSecs( time) ;
}

#else

#include <chrono>

CStopWatch::CStopWatch(){
    timer.start = std::chrono::steady_clock::time_point();
    timer.stop = std::chrono::steady_clock::time_point();
}

void CStopWatch::startTimer() {
    timer.start = std::chrono::steady_clock::now();
}

void CStopWatch::stopTimer() {
    timer.stop = std::chrono::steady_clock::now();
}

double CStopWatch::getElapsedTime() {
    using namespace std::chrono;
    duration<double> diff = duration_cast<duration<double>>(timer.stop - timer.start);
    return diff.count();
}

#endif
