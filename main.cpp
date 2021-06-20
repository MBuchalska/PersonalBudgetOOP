#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget budget("users.xml", "incomes.xml", "expenses.xml");
    char znak;

    cout << "Witaj w aplikacji do obslugi budzetu osobistego" << endl;

    while (true) {
        cout<< endl;
        cout << "Co chcesz zrobic:" << endl;
        cout << "1. Rejestracja nowego uzytkownika" << endl;
        cout << "2. Logowanie uzytkownika" << endl;
        cout << "9. Koniec pracy" << endl;
        cin >> znak;

        system("cls");

        switch (znak) {
        case '1':
            budget.RegisterUser();
            break;
        case '2': {
            budget.LoginUser();

            while (budget.IsUserLogedIn()==true) {
                cout << endl;
                cout << "Wybierz co chcesz zrobic" << endl;
                cout << "1. Dodaj przychod" << endl;
                cout << "2. Dodaj wydatek" << endl;
                cout << "3. Bilans z biezcego miesiaca" << endl;
                cout << "4. Bilans z poprzedniego miesiaca" << endl;
                cout << "5. Bilans z wybranego okresu" << endl;
                cout << "6. Zmiana hasla" << endl;
                cout << "9. Wyloguj" << endl;
                cin >> znak;

                system("cls");
                switch (znak) {
                case '1': budget.AddIncome(); break;
                case '2': budget.AddExpense(); break;
                case '3': budget.ThisMonthBudgetBalance(); break;
              case '4': budget.LastMonthBudgetBalance(); break;
             case '5': budget.AnyPeriodBudgetBalance(); break;
               case '6':   budget.ChangeUserPassword(); break;
               case '9':
                    budget.LogoutUser();
                    break;
                }
            }
        }
        break;


        case '9': {
            cout<<"Koniec pracy. Dziekujemy za skorzystanie z programu"<<endl;
            exit(0);
        }
        break;
        }
    }

    return 0;
}

