#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "ExpensesFile.h"
#include "Markup.h"
#include "HelpingMethods.h"
#include "UserManager.h"


using namespace std;

class ExpenseManager {

    const int USER_ID;
    vector <Expense> expenses;
    ExpensesFile expensesFile;

    Expense writeDataOfTheNewExpense();
    void showExpenses();

public:
    ExpenseManager (int userId) :
        USER_ID(userId) {
        expenses = expensesFile.loadExpensesFromFile(USER_ID);
    };
    void addExpense();
};

#endif
