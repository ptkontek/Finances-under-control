# include "UserManager.h"

void UserManager::userRegistration() {
    User user = writeDataOfTheNewUser();
    UsersFile usersFile;

    users.push_back(user);
    addUserToFile(user);

    cout << endl << "Account successfully created." << endl << endl;

    showAllUsers();
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
    name = HelpingMethods::loadTheLine();
    user.setName(name);
    cout << "Enter surname: ";
    surname = HelpingMethods::loadTheLine();
    user.setSurname(surname);

    do {
        cout << "Enter login: ";
        login = HelpingMethods::loadTheLine();
        user.setLogin(login);
    } while (isLoginExsist(user.getLogin())== true);


    cout << "Enter password: ";
    password = HelpingMethods::loadTheLine();
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
    login = HelpingMethods::loadTheLine();
    user.setLogin(login);

    for (int i = 0; i < users.size(); i++) {

        if (users[i].getLogin() == login) {

            for (int number = 3; number > 0; number--) {
                cout << "Enter password. Number of attempts: " << number << ": ";

                cin >> password;
                user.setPassword(password);

                if (users[i].getPassword() == password) {
                    userIdAfterLoggedIn = users[i].getId();
                    cout << endl << "You logged in." << endl << endl;
                    cout << "User id after logged in" << userIdAfterLoggedIn << endl;

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

void UserManager::changeUserPassword() {
    CMarkup xml;
    User user;
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = HelpingMethods::loadTheLine();
    user.setPassword(newPassword);

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == userIdAfterLoggedIn) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");

            bool fileExists = xml.Load( "users.xml" );

            if (!fileExists) {
                xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            }
            xml.ResetMainPos();;
            xml.FindElem();
            xml.IntoElem();

            while ( xml.FindElem("User") ) {

                xml.IntoElem();
                xml.FindElem("Id");
                if ( atoi( MCD_2PCSZ(xml.GetData())) == userIdAfterLoggedIn ) {
                    xml.FindElem("Password");
                    xml.RemoveElem();
                    xml.AddElem("Password",newPassword);

                }
                xml.OutOfElem();
                    xml.Save("users.xml");
            }

        }
    }
}

vector <User> UserManager::loadUsersFromFile() {

    CMarkup xml;
    User user;
    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") ) {

        xml.IntoElem();
        xml.FindElem( "Id" );
        user.setId( atoi( MCD_2PCSZ(xml.GetData())));

        xml.FindElem( "Name" );
        user.setName(xml.GetData());

        xml.FindElem( "Surname" );
        user.setSurname(xml.GetData());

        xml.FindElem( "Login" );
        user.setLogin(xml.GetData());

        xml.FindElem( "Password" );
        user.setPassword(xml.GetData());

        users.push_back(user);

        xml.OutOfElem();
    }
    return users;
}
void UserManager::addUserToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save("users.xml");
}
