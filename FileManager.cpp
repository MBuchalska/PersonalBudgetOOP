#include <iostream>
#include "FileManager.h"
#include <windows.h>

using namespace std;

void FileManager::AddUserToFile(UserData user) {
    bool fileExists = xml.Load(USER_FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();
    int ID=user.getUserID();
    string stringID=to_string(ID);
    xml.AddElem("UserId",stringID);
    xml.AddElem("Login",user.getUserLogin());
    xml.AddElem("Password",user.getUserPassword());
    xml.AddElem("Name",user.getFirstName());
    xml.AddElem("Surname",user.getSurname());

    xml.OutOfElem();
    xml.Save(USER_FILE_NAME);
}

vector <UserData> FileManager::DownloadUsersFromFile() {
    vector <UserData> users;
    UserData USER;
    string TempString;

    xml.Load(USER_FILE_NAME);
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User")) {
        xml.IntoElem();

        xml.FindElem("UserId");
        TempString=xml.GetData();
        int x=atoi(TempString.c_str());
        USER.setUserID(x);

        xml.FindElem("Login");
        TempString=xml.GetData();
        USER.setUserLogin(TempString);

        xml.FindElem("Password");
        TempString=xml.GetData();
        USER.setUserPassword(TempString);

        xml.FindElem("Name");
        TempString=xml.GetData();
        USER.setFirstName(TempString);

        xml.FindElem("Surname");
        TempString=xml.GetData();
        USER.setSurname(TempString);

        xml.OutOfElem();
        users.push_back(USER);
    }

    return users;
}

void FileManager::ChangeUserPasswordInTheFile(int LoggedUserID, string NewPassword) {
    string TempString;
    xml.Load(USER_FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("UserId");
        TempString=xml.GetData();
        int x=atoi(TempString.c_str());
        if (x==LoggedUserID) {
            xml.FindElem("Password");
            xml.SetElemContent(NewPassword);
        }
        xml.OutOfElem();
        xml.Save(USER_FILE_NAME);
    }
}
