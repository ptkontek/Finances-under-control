#include "UsersFile.h"

vector <User> UsersFile::loadUsersFromFile() {

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
