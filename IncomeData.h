#include <iostream>
#include "BudgetData.h"
#ifndef INCOMEDATA_h
#define INCOMEDATA_h

using namespace std;

class IncomeData: public BudgetData{

public:
    IncomeData(int IID=0, int UID=0, string day="", int num=0, string thing="", float cash=0)
    :BudgetData(IID,UID,day,num,thing,cash){};
};

#endif // INCOMEDATA_h
