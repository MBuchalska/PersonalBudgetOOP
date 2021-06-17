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
    string getToday();                          // getter for Today date
    string getPreviousMonth();                  // getter for PreviousMonth date
    bool IsTheDateCorrect(string Date);         // checks if the date is correct at many levels
    int ConvertDateToInt(string Date);          // converts date to number
};



#endif // TIMEMANAGER_h
