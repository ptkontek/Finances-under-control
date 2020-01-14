#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <windows.h>
#include <vector>
#include "Expense.h"
#include "Markup.h"
#include "DateManager.h"
#include "HelpingMethods.h"

using namespace std;

class ExpensesFile {
    int lastExpenseId;
    Expense expense;
    DateManager dateManager;
    //string date;

public:
    ExpensesFile() {
    lastExpenseId = 0;
    };


    vector <Expense> loadExpensesFromFile(int userIdAfterLoggedIn);
    void addExpenseToFile(Expense expense);
    void showExpenses();
    int getLastExpenseId();

};

#endif
