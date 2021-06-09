#include <iostream>
#include "UserManager.h"

using namespace std;

void UserManager::RegisterUser() {
    string TempString;
    int ID=0;
    NumberOfUsers=users.size();

    system("cls");

    cout << "Rejestracja nowego uzytkownika" << endl;
    cout << "Podaj dane" << endl;

    ID=NumberOfUsers+1;
    user.setUserID(ID);

    cout << "Podaj login: " << endl;
    cin >> TempString;
    user.setUserLogin(TempString);

    cout << "Podaj haslo: " << endl;
    cin >> TempString;
    user.setUserPassword(TempString);

    cout << "Podaj swoje imie: " << endl;
    cin >> TempString;
    user.setFirstName(TempString);

    cout << "Podaj swoje nazwisko: " << endl;
    cin >> TempString;
    user.setSurname(TempString);

    users.push_back(user);
   // PrintAllUsers(users);               //temporary
    file.AddUserToFile(user);

    system ("pause");
}

void UserManager::PrintAllUsers(vector <UserData> users) {
    NumberOfUsers=users.size();

    for(int i=0; i<NumberOfUsers; i++) {
        user=users[i];
        cout << endl;
        cout << "ID: " << user.getUserID() << endl;
        cout << "Login: " << user.getUserLogin() << endl;
        cout << "Haslo: " << user.getUserPassword() << endl;
        cout << "Imie uzytkownika: " << user.getFirstName() << endl;
        cout << "Nazwisko uzytkownika: " << user.getSurname() << endl;
    }
}
