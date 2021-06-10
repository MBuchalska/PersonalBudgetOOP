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

    cout << "Podaj login: ";
    cin >> TempString;
    user.setUserLogin(TempString);
    cout<<endl;

    cout << "Podaj haslo: ";
    cin >> TempString;
    user.setUserPassword(TempString);
    cout<<endl;

    cout << "Podaj swoje imie: ";
    cin >> TempString;
    user.setFirstName(TempString);
    cout<<endl;

    cout << "Podaj swoje nazwisko: ";
    cin >> TempString;
    user.setSurname(TempString);
    cout<<endl;

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

int UserManager::LoginUser() {
    string TempLogin="", TempPassword="", login="", pass="";

    system("cls");
    NumberOfUsers=users.size();
    cout << "Logowanie uzytkownika" << endl;
    cout << "Podaj nazwe uzytkownika: " ;
    cin >> TempLogin;
    cout <<endl;

    for (int i=0; i<NumberOfUsers; i++) {
        user=users[i];
        login = user.getUserLogin();
        pass = user.getUserPassword();

        if (login==TempLogin) {
            cout << "Znaleziono login w bazie." << endl;
            for (int j=3; j>0; j--) {
                cout << "Podaj haslo: ";
                cin >> TempPassword;
                cout<<endl;

                if (pass==TempPassword) {
                    cout << "Logowanie poprawne" <<endl;
                    cout << "Witaj " << login << endl;
                    LoggedUserID=user.getUserID();
                    return LoggedUserID;

                } else {
                    cout << "Haslo niepoprawne. Pozostalo prob: " << j-1 << endl;
                }
            }
            cout << "Logowanie nieudane. Podano 3 razy niepoprawne haslo." << endl;
            return 0;
        }
    }
    cout << "Logowanie nieudane. Nie ma takiego uzytkownika w bazie." << endl;
    return 0;
}

int UserManager::getLoggedUserID() {
    return LoggedUserID;
}

void UserManager::setLoggedUserID(int ID){
LoggedUserID=ID;
}
