#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include "UserManager.h"
#include "HelpingMethods.h"
#include "IncomeManager.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;
    IncomeManager *incomeManager;


public:
    PersonalBudget() { //stworzyc stale nazwy plikow
        incomeManager = NULL;
    };
    ~PersonalBudget() {
        delete incomeManager;
        incomeManager = NULL;
    }
    void userRegistration();
    void userLogin();
    void showAllUsers();
    void changeUserPassword();
    void logOutTheUser();
    bool isTheUserLoggedIn();
    void addIncome();

    char selectOptionFromTheUserMenu();
    char selectOptionFromTheMainMenu();
};

#endif
