#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{
    int incomeId, userId, date;
    string item;
    float amount;

public:
    Income(int incomeId=0, int userId=0, int date=0, string item="", float amount=0) {
    this->incomeId = incomeId;
    this->userId = userId;
    this->date = date;
    this->item = item;
    this->amount = amount;
    };

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float Amount);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};
#endif
