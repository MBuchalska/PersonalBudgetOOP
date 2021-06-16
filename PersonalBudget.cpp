#include <iostream>
#include "PersonalBudget.h"

using namespace std;

void PersonalBudget::RegisterUser() {
    user.RegisterUser();
}

void PersonalBudget::LoginUser() {
    int ID=user.LoginUser();
    system ("pause");
    if(ID>0) {
        income = new BudgetManager(INCOME_FILE_NAME, ID);
        expence = new BudgetManager(ID, EXPENCE_FILE_NAME);
    }
}

bool PersonalBudget::IsUserLogedIn() {
    if (user.getLoggedUserID()==0) return false;
    else return true;
}

void PersonalBudget::LogoutUser() {
    user.setLoggedUserID(0);
    delete income;
    delete expence;
    income=NULL;
    expence=NULL;
    cout << "Uzytkownik zostal wylogowany. Dziekujemy za skorzystanie z programu" << endl;
}

void PersonalBudget::ChangeUserPassword() {
    int ID=user.getLoggedUserID();
    user.ChangeUserPassword(ID);
}

void PersonalBudget::AddIncome() {
    system ("cls");
    int ID=user.getLoggedUserID();
    string BudgetTags[4]= {"Incomes", "Income", "IncomeID", "przychod"};
    vector <BudgetData> budget=income->getIncomesVector();
    income->AddNewBudgetData(ID, INCOME_FILE_NAME, NumberOfIncomes, BudgetTags, budget);
    NumberOfIncomes++;
    budget.clear();
}
