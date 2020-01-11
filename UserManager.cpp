# include "UserManager.h"

void UserManager::userRegistration() {
    User user = writeDataOfTheNewUser();
    UsersFile usersFile;

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Account successfully created." << endl << endl;
    system("pause");
}

void UserManager::showAllUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout <<users[i].getId() << endl;
        cout <<users[i].getName() << endl;
        cout <<users[i].getSurname() << endl;
        cout <<users[i].getLogin() << endl;
        cout <<users[i].getPassword() << endl;
    }
}

User UserManager::writeDataOfTheNewUser() {
    User user;
    string name, surname, login, password;
    user.setId(getNewUserId());

    cout << "Enter name: " ;
    cin >> name;
    user.setName(name);
    cout << "Enter surname: ";
    cin >> surname;
    user.setSurname(surname);

    do {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExsist(user.getLogin())== true);


    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExsist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Such login already exsist." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::userLogin() {
    User user;
    string login, password;

    cout << endl << "Enter login: ";
    cin >> login;
    //login = HelpingMethods::wczytajLinie();
    user.setLogin(login);

    for (int i = 0; i < users.size(); i++) {

        if (users[i].getLogin() == login) {

            for (int i = 3; i > 0; i--) {
                cout << "Enter password. Number of attempts: " << i << ": ";

                cin >> password;
                user.setPassword(password);

                if (users[i].getPassword() == password) {
                    userIdAfterLoggedIn = users[i].getId();
                    cout << endl << "You logged in." << endl << endl;

                    system("pause");
                    return userIdAfterLoggedIn;
                }
            }
            cout << "Password entered incorrectly 3 times." << endl;
            system("pause");
            return 0;
        }
    }
    cout<< "No user with such login." << endl << endl;
    system("pause");
    return 0;
}

void UserManager::logOutTheUser() {
    userIdAfterLoggedIn = 0;
}

bool UserManager::isTheUserLoggedIn() {
    if (userIdAfterLoggedIn > 0)
        return true;
    else
        return false;
}

int UserManager::getUserIdAfterLoggedIn() {
    return userIdAfterLoggedIn;
}
