#include <iostream>
#include "FileManager.h"
#include "TimeManager.h"
#include <windows.h>
#include <string>
#include <sstream>

using namespace std;

FileManager::FileManager() {};

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

int FileManager::HowManyBudgetData(string BudgetFileName) {
    int counter=0;

    bool fileExists = xml.Load(BudgetFileName);

    if(!fileExists) return 0;
    else {
        xml.Load(BudgetFileName);
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem()==true) {
            counter++;
        }
        return counter;
    }
}

void FileManager::AddBudgetDataToFile(BudgetData budget, string BudgetFileName, string BudgetTags[]) {
    string TempString;
    int ID;

    bool fileExists = xml.Load(BudgetFileName);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(BudgetTags[0]);
    }
    xml.FindElem();
    xml.IntoElem();

    xml.AddElem(BudgetTags[1]);
    xml.IntoElem();
    ID=budget.getBudgetID();
    TempString=to_string(ID);
    xml.AddElem(BudgetTags[2],TempString);

    ID=budget.getUserID();
    TempString=to_string(ID);
    xml.AddElem("UserID",TempString);

    xml.AddElem("date",budget.getDate());
    xml.AddElem("item",budget.getItem());

    float x=budget.getAmount();
    stringstream sstream;
    sstream<<x;
    TempString=sstream.str();
    xml.AddElem("amount",TempString);

    xml.OutOfElem();
    xml.Save(BudgetFileName);
}


vector <BudgetData> FileManager::DownloadBudgetDataFromFile(int UserID, string BudgetFileName, string BudgetTag) {
    BudgetData budget;
    vector <BudgetData> budgets;
    string TempString;
    int TempInt;

    bool fileExists = xml.Load(BudgetFileName);
    if (!fileExists) cout<<"Plik z bud¿etem nie istnieje. Dodaj jakieœ pozycje bud¿etowe"<<endl;

    else {
        xml.FindElem();
        xml.IntoElem();

        while(xml.FindElem()==true) {
            xml.IntoElem();

            xml.FindElem(BudgetTag);
            TempString=xml.GetData();
            TempInt=atoi(TempString.c_str());
            budget.setBudgetID(TempInt);

            xml.FindElem("UserID");
            TempString=xml.GetData();
            int y=atoi(TempString.c_str());

            if(y==UserID){
            budget.setUserID(y);

            xml.FindElem("UserID");
            TempString=xml.GetData();
            TempInt=atoi(TempString.c_str());
            budget.setUserID(TempInt);

            xml.FindElem("date");
            TempString=xml.GetData();
            budget.setDate(TempString);

            TimeManager time;
            TempInt=time.ConvertDateToInt(TempString);
            budget.setDateAsNumber(TempInt);

            xml.FindElem("item");
            TempString=xml.GetData();
            budget.setItem(TempString);

            xml.FindElem("amount");
            TempString=xml.GetData();
            float x=stof(TempString);
            budget.setAmount(x);

            budgets.push_back(budget);
            }

            xml.OutOfElem();
        }
    }

    return budgets;
}
