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

    struct sortByDate {
        inline bool operator()( Expense& struct1,  Expense& struct2) {
            return (struct1.getDate() < struct2.getDate());
        }
    };

public:
    ExpenseManager (int userId) :
        USER_ID(userId) {
        expenses = expensesFile.loadExpensesFromFile(USER_ID);
    };
    void addExpense();
    void sortExpenses();
    float calculateExpensesFromTheCurrentMonth();
    float calculateExpensesFromThePreviousMonth();
    float calculateExpensesFromTheTimeInterval(int startDate, int endDate);
};

#endif
