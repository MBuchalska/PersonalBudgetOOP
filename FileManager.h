#include <iostream>
#include "UserData.h"
#include "Markup.h"
#include <vector>
#ifndef FILEMANAGER_h
#define FILEMANAGER_h

using namespace std;

class FileManager {
    const string USER_FILE_NAME;
    CMarkup xml;

public:
    FileManager();
    FileManager(string USERFILENAME)    //constructor with const UserFileName
        :USER_FILE_NAME(USERFILENAME) {};

    void AddUserToFile(UserData user);          // adds single user data to XML file
    vector <UserData> DownloadUsersFromFile();  //downloads all users from XML file
    void ChangeUserPasswordInTheFile(int LoggedUserID, string NewPassword);  // changes user password in the file
    int HowManyBudgetData(string BudgetFileName, string BudgetTag);         //checks number of incomes and expences
};
#endif // FILEMANAGER_h
