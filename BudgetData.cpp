#include <iostream>
#include "BudgetData.h"

using namespace std;

void BudgetData::setBudgetID(int newBID) {
    BudgetID=newBID;
}

void BudgetData::setUserID(int newUID) {
    UserID=newUID;
}

void BudgetData::setDate(string newDate) {
    date=newDate;
}

void BudgetData::setDateAsNumber(int newDN) {
    dateAsNumber=newDN;
}

void BudgetData::setItem(string itemName) {
    item=itemName;
}

void BudgetData::setAmount(float money) {
    amount=money;
}

int BudgetData::getBudgetID() {
    return BudgetID;
}

int BudgetData::getUserID() {
    return UserID;
}

string BudgetData::getDate() {
    return date;
}

int BudgetData::getDateAsNumber() {
    return dateAsNumber;
}

string BudgetData::getItem() {
    return item;
}

float BudgetData::getAmount() {
    return amount;
}

bool operator < (const BudgetData &b1, const BudgetData &b2) {
    if (b1.dateAsNumber<=b2.dateAsNumber) return true;
    else return false;
}


