#include <iostream>
#ifndef USERDATA_h
#define USERDATA_h


using namespace std;

class UserData {
    int UserID;
    string UserLogin, UserPassword, FirstName, Surname;

public:
    void setUserID(int newID);
    void setUserLogin(string newLogin);
    void setUserPassword(string newPassword);
    void setFirstName(string newFirstName);
    void setSurname(string newSurname);

    int getUserID();
    string getUserLogin();
    string getUserPassword();
    string getFirstName();
    string getSurname();

};

#endif // USERDATA_h
