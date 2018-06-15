#ifndef TIMER_H
#define TIMER_H

#ifdef _WIN32
#include <windows.h>    // Implementation only works on windows
#endif

#include "System.h"

class Timer
{
public:
    Timer() { getQuantum(); start(); }
    inline void start() {
#ifdef _WIN32
        QueryPerformanceCounter((LARGE_INTEGER*) &_startTime); 
#else
        assert(0);
#endif
    }
    double elapsedTime() { Timer curr;   return  (double(curr._startTime - _startTime) * getQuantum()); }
    inline static double getQuantum() { 
#ifdef _WIN32
        int64_t  ticksPerSec  = 0;
        QueryPerformanceFrequency((LARGE_INTEGER*) &ticksPerSec);
        return 1.0 / double(ticksPerSec);
#else
        assert(0);
#endif
    }
private:
    int64_t _startTime;
};

#endif