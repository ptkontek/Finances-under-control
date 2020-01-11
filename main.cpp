#include <iostream>
#include "Markup.h"
#include <windows.h>
#include <winbase.h>
#include <ctime>
#include <vector>
#include "HelpingMethods.h"
#include "DateManager.h"
#include "Income.h"
#include "IncomesFile.h"
#include "UsersFile.h"
#include "UserManager.h"

using namespace std;

int main() {

    CMarkup xml;
    UserManager userManager;
    User user;
    DateManager dateManager;

    //date = dateManager.enterDate();
    // convertDate = dateManager.convertDateToInt();

    IncomesFile incomesFile;
    incomesFile.loadIncomesFromFile();

    //incomesFile.addIncomeToFile();
    incomesFile.showIncomes();
    dateManager.howManyDaysHasMonth();

    //UsersFile usersFile;
    //usersFile.loadUsersFromFile();
   // usersFile.addUserToFile(user);

   // userManager.showAllUsers();

    return 0;
}
