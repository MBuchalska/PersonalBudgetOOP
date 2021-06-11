#include <iostream>
#include <ctime>
#include <cstdio>
#ifndef TIMEMANAGER_h
#define TIMEMANAGER_h

using namespace std;

class TimeManager {
    string Today;
    string PreviousMonth;
    int DaysInMonths[13]={31,28,31,30,31,30,31,31,30,31,30,31,29};

    string WhatDayIsToday();
    string BeginingOfLastMonth();

public:
    TimeManager();
};



#endif // TIMEMANAGER_h
