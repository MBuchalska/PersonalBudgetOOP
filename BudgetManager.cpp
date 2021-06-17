#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "BudgetManager.h"
#include "TimeManager.h"


using namespace std;

vector <BudgetData> BudgetManager::getIncomesVector() {
    return incomes;
}
vector <BudgetData> BudgetManager::getExpencesVector() {
    return expences;
}

void BudgetManager::AddNewBudgetData(int LOGGED_USER_ID, string BudgetFileName, int NumberOfBudgetData, string BudgetTags[], vector <BudgetData>& budget) {
    BudgetData SingleBudget;
    string GivenDate, TempString="";
    int DateNumber;
    char answer;
    TimeManager timeData;

    cout << "Dododaj nowy " << BudgetTags[3] << endl;
    cout << "Podawaj kolejne dane zgodnie z instrukcjami" << endl;

    int ID=NumberOfBudgetData+1;
    SingleBudget.setBudgetID(ID);

    SingleBudget.setUserID(LOGGED_USER_ID);

    cout << "Czy to " << BudgetTags[3] << " z dnia dzisiejszego (y/n)" << endl;
    cin >> answer;

    if (answer=='y') {
        GivenDate=timeData.getToday();
        SingleBudget.setDate(GivenDate);
    } else {
        cout << "Podaj date w formacie yyyy-mm-dd" << endl;
        cout << "Data musi byc pozniejsza niz 2000-01-01" <<endl;
        do {
            cin>>GivenDate;
        } while (timeData.IsTheDateCorrect(GivenDate)==false);
        SingleBudget.setDate(GivenDate);
    }

    DateNumber=timeData.ConvertDateToInt(GivenDate);
    SingleBudget.setDateAsNumber(DateNumber);

    cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
    cout<<"Czego dotyczy ten " << BudgetTags[3] <<"? (np. zabawki dla kota, warzywa)" << endl;
    getline(cin,TempString);
    SingleBudget.setItem(TempString);

    cout << "Podaj kwote dla "<< BudgetTags[3] << " z dokladnoscia do 2 miejsc po przecinku" << endl;
    cin >> TempString;
    string ToFind=",";
    int place=TempString.find(ToFind);
    if (place!=string::npos) {
        string replacement =".";
        TempString.replace(place,1,replacement);
    }
    float amount=stof(TempString);
    SingleBudget.setAmount(amount);

    budget.push_back(SingleBudget);
    file.AddBudgetDataToFile(SingleBudget, BudgetFileName, BudgetTags);

    cout << BudgetTags[3] << " dodany" << endl;
    system("pause");
}

void BudgetManager::PrintBudgetData(vector <BudgetData> budgets, string BudgetTag){
BudgetData budget;
int sizeOfBudgets = budgets.size();

for (int i=0; i<sizeOfBudgets; i++){
    budget=budgets[i];
        cout << BudgetTag << ": " << budget.getBudgetID() << endl;
        cout << "UserID: " << budget.getUserID() << endl;              //temporary
        cout << "data: " << budget.getDate() << endl;
        cout << "Data int: " << budget.getDateAsNumber() << endl;       //temporary
        cout << "Item: " << budget.getItem() << endl;
        cout << "Amount: " << budget.getAmount() << endl;
        cout << endl;
}
}
