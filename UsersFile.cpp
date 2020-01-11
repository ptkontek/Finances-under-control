#include "UsersFile.h"

/*vector <User> UsersFile::loadUsersFromFile() {

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

void UsersFile::addUserToFile(User user) {
    CMarkup xml;
    int id;
    //User user;
    string name, surname, login, password;
    UserManager userManager;
    userManager.writeDataOfTheNewUser();

    cout << "Enter id: " << endl;
    cin >> id;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter surname" << endl;
    cin >> surname;
    cout << "Enter login";
    cin >> login;
    cout << "Enter password";
    cin >> password;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", id);
    xml.AddElem("Name", name);
    xml.AddElem("Surname", surname);
    xml.AddElem("Login", login);
    xml.AddElem("Password", password);

    xml.Save("Users.xml");
}*/
