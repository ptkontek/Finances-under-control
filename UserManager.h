#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include "Markup.h"
#include "HelpingMethods.h"

using namespace std;

class UserManager {

    int userIdAfterLoggedIn;
    vector <User> users;
    UsersFile usersFile;

    int getNewUserId();
    bool isLoginExsist(string login);
    User writeDataOfTheNewUser();


public:
    UserManager() {
        userIdAfterLoggedIn = 0;
        users = usersFile.loadUsersFromFile();
    }
    void userRegistration();
    int userLogin();
    void showAllUsers();
    void changeUserPassword();
    void logOutTheUser();

    int getUserIdAfterLoggedIn();
    bool isTheUserLoggedIn();

};

#endif
