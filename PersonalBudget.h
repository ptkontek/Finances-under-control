#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include "UserManager.h"
#include "HelpingMethods.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;


public:
    PersonalBudget() {};
    void userRegistration();
    void userLogin();
    void showAllUsers();
    void changeUserPassword();
    void logOutTheUser();
    bool isTheUserLoggedIn();

    char selectOptionFromTheUserMenu();
    char selectOptionFromTheMainMenu();
};

#endif
