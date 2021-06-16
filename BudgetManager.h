#include <iostream>
#include "BudgetData.h"
#include "FileManager.h"
#ifndef BUDGETMANAGER_h
#define BUDGETMANAGER_h

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;
    FileManager file;
    string IncomeIDTag, ExpenceIDTag;
    vector <BudgetData> incomes;
    vector <BudgetData> expences;

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

    vector <BudgetData> getIncomesVector();
    vector <BudgetData> getExpencesVector();
    void AddNewBudgetData(int LOGGED_USER_ID, string BudgetFileName, int NumberOfBudgetData, string BudgetTags[], vector <BudgetData>& budget);
};

#endif // BUDGETMANAGER_h
