#include <iostream>
#include "UserData.h"
#include "Markup.h"
#include "BudgetData.h"
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
    int HowManyBudgetData(string BudgetFileName);         //checks number of incomes and expences
    void AddBudgetDataToFile(BudgetData budget, string BudgetFileName, string BudgetTags[]); //adds income or expence to file
    vector <BudgetData> DownloadBudgetDataFromFile(int UserID, string BudgetFileName, string BudgetTag); // downloads budget data from file
};
#endif // FILEMANAGER_h
