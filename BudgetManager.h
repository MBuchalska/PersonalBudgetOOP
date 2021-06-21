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

    void PrintBudgetData(vector <BudgetData>& budgets, string BudgetTag); // Prints budget data on screen
    float BudgetSum(vector <BudgetData>& budgets, string BudgetTag, int Time1, int Time2);  // sums incomes or expenses

public:
    BudgetManager(int LoggedUserID):LOGGED_USER_ID(LoggedUserID) {};
    BudgetManager(string IncomeFileName, int LoggedUserID)
        :file(IncomeFileName), LOGGED_USER_ID(LoggedUserID) {
        IncomeIDTag="IncomeID";
        incomes=file.DownloadBudgetDataFromFile(LOGGED_USER_ID, IncomeFileName, IncomeIDTag); // downloads income data from the file
        // PrintBudgetData(incomes, IncomeIDTag);
    };

    BudgetManager(int LoggedUserID, string ExpenceFileName)
        :LOGGED_USER_ID(LoggedUserID), file(ExpenceFileName)  {
        ExpenceIDTag="ExpenseID";
        expences=file.DownloadBudgetDataFromFile(LOGGED_USER_ID, ExpenceFileName, ExpenceIDTag); // downloads expense data from the file
        // PrintBudgetData(expences, ExpenceIDTag);
    };

    vector <BudgetData> getIncomesVector();
    vector <BudgetData> getExpencesVector();
    void AddNewBudgetData(int LOGGED_USER_ID, string BudgetFileName, int NumberOfBudgetData, string BudgetTags[], vector <BudgetData>& budget);
    void BudgetBalance(int Time1, int Time2, vector <BudgetData>& incomes, vector <BudgetData>& expences);
 // friend bool BudgetData::SortByDate(const BudgetData &b1, const BudgetData &b2);

};

#endif // BUDGETMANAGER_h
