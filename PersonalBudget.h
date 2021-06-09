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
};

#endif // PERSONALBUDGET_h



