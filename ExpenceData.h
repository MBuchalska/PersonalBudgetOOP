#include <iostream>
#include "BudgetData.h"
#ifndef EXPENCEDATA_h
#define EXPENCEDATA_h

using namespace std;

class ExpenceData: public BudgetData{

public:
    ExpenceData(int EID=0, int UID=0, string day="", int num=0, string thing="", float cash=0)
    :BudgetData(EID,UID,day,num,thing,cash){};
};

#endif // EXPENCEDATA_h
