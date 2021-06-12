#include <iostream>
#include <string>
#include "TimeManager.h"

using namespace std;

TimeManager::TimeManager() {
    Today=WhatDayIsToday();
  //  cout<<Today<<endl;
    PreviousMonth=BeginingOfLastMonth();
  //  cout<<PreviousMonth<<endl;
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

string TimeManager::getToday() {
    return Today;
}

string TimeManager::getPreviousMonth() {
    return PreviousMonth;
}

bool TimeManager::IsTheDateCorrect(string Date) {
    if (Date.length()!=10) {
        cout << "Nieprawidlowy format daty" << endl;
        cout << "Podaj date ponownie w formacie rrrr-mm-dd" << endl;
        return false;
    }

    int year=0, month=0, day=0, liczba;
    char znak;
    for (int i=0; i<10; i++) {
        znak=Date[i]-48;
        liczba=znak;
        switch (i) {
        case 0:
            year+=liczba*1000;
            break;
        case 1:
            year+=liczba*100;
            break;
        case 2:
            year+=liczba*10;
            break;
        case 3:
            year+=liczba;
            break;
        case 4:
            liczba=0;
            break;
        case 5:
            month+=liczba*10;
            break;
        case 6:
            month+=liczba;
            break;
        case 7:
            liczba=0;
            break;
        case 8:
            day+=liczba*10;
            break;
        case 9:
            day+=liczba;
            break;
        }
    }

    if (year<2000) {
        cout << "Program przyjmuje daty powyzej roku 2000"  << endl;
        cout << "Podaj date z poprawnego zakresu" << endl;
        return false;
    } else if ((month<1)||(month>12)) {
        cout << "Nieprawidlowy miesiac"<<endl;
        cout << "Miesiace numerujemy 01-12"<< endl;
        cout << "Podaj date ponownie" << endl;
        return false;
    } else if((month==2)&&(((year%4==0)&&(year%100!=0))||(year%400==0))) {
        if (day>29) {
            cout <<"W roku przestepnym luty ma maksymalnie 29 dni" <<endl;
            cout <<"Podaj prawidlowa date" <<endl;
            return false;
        } else if (day>28) {
            cout <<"W roku przestepnym luty ma maksymalnie 28 dni" <<endl;
            cout <<"Podaj prawidlowa date" <<endl;
            return false;
        }
    } else if (day>DaysInMonths[month-1]) {
        cout << "Ten miesiac moze miec maksymalnie " << DaysInMonths[month-1] << " dni" << endl;
        cout <<"Podaj prawidlowa date" <<endl;
        return false;
    }

    return true;
}
