#include <iostream>
//#include "BudgetData.h"
#include "FileManager.h"
#include "IncomeData.h"
#include "ExpenceData.h"
#ifndef BUDGETMANAGER_h
#define BUDGETMANAGER_h

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;
    FileManager file;
    string IncomeIDTag, ExpenceIDTag;
    vector <IncomeData> incomes;
    vector <ExpenceData> expences;

public:
    BudgetManager(string IncomeFileName, int LoggedUserID)
        :file(IncomeFileName), LOGGED_USER_ID(LoggedUserID) {
        IncomeIDTag="IncomeID";
        //wci¹gnij z pliku incomes do wektora incomes=
    };

    BudgetManager(int LoggedUserID, string ExpenceFileName)
        :LOGGED_USER_ID(LoggedUserID), file(ExpenceFileName)  {
        ExpenceIDTag="ExpenceID";
        //wci¹gnij z pliku expences do wektora expences=
    };
};

#endif // BUDGETMANAGER_h
