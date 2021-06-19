#include <iostream>
#include "PersonalBudget.h"
#include "TimeManager.h"


using namespace std;

void PersonalBudget::RegisterUser() {
    user.RegisterUser();
}

void PersonalBudget::LoginUser() {
    int ID=user.LoginUser();
    system ("pause");
    if(ID>0) {
        income = new BudgetManager(INCOME_FILE_NAME, ID);
        expense = new BudgetManager(ID, EXPENCE_FILE_NAME);
    }
}

bool PersonalBudget::IsUserLogedIn() {
    if (user.getLoggedUserID()==0) return false;
    else return true;
}

void PersonalBudget::LogoutUser() {
    user.setLoggedUserID(0);
    delete income;
    delete expense;
    income=NULL;
    expense=NULL;
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

void PersonalBudget::AddExpense() {
    system ("cls");
    int ID=user.getLoggedUserID();
    string BudgetTags[4]= {"Expenses", "Expense", "ExpenseID", "wydatek"};
    vector <BudgetData> budget=expense->getExpencesVector();
    expense->AddNewBudgetData(ID, EXPENCE_FILE_NAME, NumberOfExpenses, BudgetTags, budget);
    NumberOfExpenses++;
    budget.clear();
}

void PersonalBudget::AnyPeriodBudgetBalance() {
    system ("cls");
    string TempString="", Date1, Date2;
    TimeManager timeData;

    cout<<"Zestawienie budzetowe z dowolnego okresu"<<endl;
    cout<<"Podaj daty graniczne" << endl;
    cout<<"Podaj zakres dat"<<endl;
    cout<<"Data poczatkowa w formacie rrrr-mm-dd: "<<endl;

    do {
        cin>>Date1;
    } while (timeData.IsTheDateCorrect(Date1)==false);

    cout<<"Data koncowa w formacie rrrr-mm-dd: " <<endl;

    int Time1=timeData.ConvertDateToInt(Date1);

    do {
        cin>>Date2;
    } while (timeData.IsTheDateCorrect(Date2)==false);

    int Time2=timeData.ConvertDateToInt(Date2);

    int ID=user.getLoggedUserID();
    BudgetManager budget(ID);
    vector <BudgetData> budget1=income->getIncomesVector();
    vector <BudgetData> budget2=expense->getExpencesVector();
    budget.BudgetBalance(Time1, Time2, budget1, budget2);

}

