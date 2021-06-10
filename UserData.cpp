#include <iostream>
#include "UserData.h"

using namespace std;

    void UserData::setUserID(int newID){
    UserID=newID;
    }

    void UserData::setUserLogin(string newLogin){
    UserLogin=newLogin;
    }

    void UserData::setUserPassword(string newPassword){
    UserPassword=newPassword;
    }

    void UserData::setFirstName(string newFirstName){
    FirstName=newFirstName;
    }

    void UserData::setSurname(string newSurname){
    Surname=newSurname;
    }

    int UserData::getUserID(){
    return UserID;
    }

    string UserData::getUserLogin(){
    return UserLogin;
    }

    string UserData::getUserPassword(){
    return UserPassword;
    }

    string UserData::getFirstName(){
    return FirstName;
    }

    string UserData::getSurname(){
    return Surname;
    }
