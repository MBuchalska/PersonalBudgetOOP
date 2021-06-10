#include <iostream>
#include "UserManager.h"
#ifndef PERSONALBUDGET_h
#define PERSONALBUDGET_h

using namespace std;


class PersonalBudget{
    UserManager user;

public:
   PersonalBudget(string UserFileName):user(UserFileName){};     //constructor
   void RegisterUser();            // registers new user
   void LoginUser();                // logins the user
   bool IsUserLogedIn();            // checks if the user is logged in
   void LogoutUser();               // loggs the user out
   void ChangeUserPassword();       // changes a password of logged user
};

#endif // PERSONALBUDGET_h



