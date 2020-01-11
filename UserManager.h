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

    //int idZalogowanegoUzytkownika;
    int userIdAfterLoggedIn;
    vector <User> users;
    //UsersFile usersFile; //kilka razy bedziemy korzystac z obiektu, wiec mozemy go tutaj utworzyc, zamiast w .cpp


    int getNewUserId();
    bool isLoginExsist(string login);


public:
    UserManager() {
        userIdAfterLoggedIn = 0;
        users = loadUsersFromFile();
    }
    void userRegistration();
    int userLogin();
    void showAllUsers();
    void changeUserPassword();
    void logOutTheUser();
    User writeDataOfTheNewUser();
    int getUserIdAfterLoggedIn();
    bool isTheUserLoggedIn();
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);

};

#endif