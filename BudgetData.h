#include <iostream>
#ifndef BUDGETDATA_h
#define BUDGETDATA_h

using namespace std;

class BudgetData {
    int BudgetID;
    int UserID;
    string date;
    int dateAsNumber;
    string item;
    float amount;

public:
    BudgetData(int BID=0, int UID=0, string day="", int num=0, string thing="", float cash=0) {
        BudgetID=BID;
        UserID=UID;
        date=day;
        dateAsNumber=num;
        item=thing;
        amount=cash;
    };

    friend bool operator < (const BudgetData &b1, const BudgetData &b2); //defines the operator for "<"

    void setBudgetID(int newBID);
    void setUserID(int newUID);
    void setDate(string newDate);
    void setDateAsNumber(int newDN);
    void setItem(string itemName);
    void setAmount(float money);

    int getBudgetID();
    int getUserID();
    string getDate();
    int getDateAsNumber();
    string getItem();
    float getAmount();
};


#endif // BUDGETDATA_h
