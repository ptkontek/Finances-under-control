#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include "UserManager.h"
#include "HelpingMethods.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;


public:
    PersonalBudget() {
        incomeManager = NULL;
        expenseManager = NULL;
    };
    ~PersonalBudget() {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    }

    void userRegistration();
    void userLogin();
    void showAllUsers();
    void changeUserPassword();
    void logOutTheUser();
    bool isTheUserLoggedIn();
    void addIncome();
    void addExpense();
    void calculateFinancesFromTheCurrentMonth();
    void calculateFinancesFromThePreviousMonth();
    void calculateFinancesFromTheTimeInterval();
    char selectOptionFromTheUserMenu();
    char selectOptionFromTheMainMenu();
};

#endif
