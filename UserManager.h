#include <iostream>
#include <vector>
#include "UserData.h"
#include "FileManager.h"
#ifndef USERMANAGER_h
#define USERMANAGER_h

using namespace std;

class UserManager{
    UserData user;
    vector <UserData> users;
    int NumberOfUsers;
    FileManager file;

    void PrintAllUsers(vector <UserData> users);  // prints all users on the screen with all data

public:
    UserManager(string UserFileName):file(UserFileName){        //constructor downloads all users to vector and declares file name
    users=file.DownloadUsersFromFile();
    PrintAllUsers(users);           //temporary
    };
    void RegisterUser();            // registers new user and adds to the file

};

#endif // USERMANAGER_h
