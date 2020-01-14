#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{
    int expenseId, userId, date;
    string item;
    float amount;

public:
    Expense(int expenseId=0, int userId=0, int date=0, string item="", float amount=0) {
    this->expenseId = expenseId;
    this->userId = userId;
    this->date = date;
    this->item = item;
    this->amount = amount;
    };

    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float Amount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};
#endif
