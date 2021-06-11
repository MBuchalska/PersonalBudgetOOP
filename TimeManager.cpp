#include <iostream>
#include <string>
#include "TimeManager.h"

using namespace std;

TimeManager::TimeManager() {
    Today=WhatDayIsToday();
    cout<<Today<<endl;
    PreviousMonth=BeginingOfLastMonth();
    cout<<PreviousMonth<<endl;
}

string TimeManager::WhatDayIsToday() {
    time_t timing;
    string TheDate="", TempString="";

    time(NULL);
    time(& timing);

    tm *timing2;
    timing2=localtime(& timing);
    int year0=timing2->tm_year + 1900;
    int month0=timing2->tm_mon+1;
    int day0=timing2->tm_mday;

    TheDate=to_string(year0)+"-";
    TempString=to_string(month0);
    if (TempString.length()==1) {
        TempString.insert(0,"0");
    }
    TheDate+=TempString+"-";

    TempString=to_string(day0);
    if (TempString.length()==1) {
        TempString.insert(0,"0");
    }
    TheDate+=TempString;

    delete timing2;

    return TheDate;
}

string TimeManager::BeginingOfLastMonth() {
    string TheDate="", TempString="";
    time_t timing;

    time(NULL);
    time(& timing);

    tm *timing2;
    timing2=localtime(& timing);
    int year0=timing2->tm_year + 1900;
    int month0=timing2->tm_mon+1;

    int PrevMonth=0;
    if (month0==1) {
        PrevMonth=12;
        year0=year0-1;
    } else PrevMonth=month0-1;


    TheDate=to_string(year0)+"-";
    TempString=to_string(PrevMonth);
    if (TempString.length()==1) {
        TempString.insert(0,"0");
    }
    TheDate+=TempString+"-01";

    delete timing2;

    return TheDate;
}
