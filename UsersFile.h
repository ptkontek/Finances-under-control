#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class UsersFile {
    vector <User> users;

public:
    UsersFile() {};
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void changePasswordInFile(int userIdAfterLoggedIn, string newPassword);

};

#endif
