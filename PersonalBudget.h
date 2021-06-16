#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"
#include "FileManager.h"
#ifndef PERSONALBUDGET_h
#define PERSONALBUDGET_h

using namespace std;


class PersonalBudget {
    UserManager user;
    const string INCOME_FILE_NAME;
    const string EXPENCE_FILE_NAME;
    BudgetManager *income;
    BudgetManager *expence;
    int NumberOfIncomes;
    int NumberOfExpences;
    FileManager file;

public:
    PersonalBudget(string UserFileName, string IncomeFileName, string ExpenceFileName) //constructor
        :user(UserFileName), INCOME_FILE_NAME(IncomeFileName),EXPENCE_FILE_NAME(ExpenceFileName) {
        user.setLoggedUserID(0);
        income=NULL;
        expence=NULL;
        NumberOfIncomes=file.HowManyBudgetData(INCOME_FILE_NAME);
       // cout << NumberOfIncomes << endl;
        NumberOfExpences=file.HowManyBudgetData(EXPENCE_FILE_NAME);
       // cout << NumberOfExpences << endl;
    }

    void RegisterUser();            // registers new user
    void LoginUser();                // logins the user
    bool IsUserLogedIn();            // checks if the user is logged in
    void LogoutUser();               // loggs the user out
    void ChangeUserPassword();       // changes a password of logged user
    void AddIncome();               //adds income to the file and vector
};

#endif // PERSONALBUDGET_h



