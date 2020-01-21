#include <iostream>
#include "Markup.h"
#include <windows.h>
#include <winbase.h>
#include <ctime>
#include <vector>
#include "PersonalBudget.h"

using namespace std;

int main() {

    CMarkup xml;
    PersonalBudget personalBudget;

    char choice;
    while (true) {
        if (personalBudget.isTheUserLoggedIn() == false) {
            choice = personalBudget.selectOptionFromTheMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.selectOptionFromTheUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.calculateFinancesFromTheCurrentMonth();
                break;
            case '4':
                personalBudget.calculateFinancesFromThePreviousMonth();
                break;
            case '5':
                personalBudget.calculateFinancesFromTheTimeInterval();
                break;
            case '6':
                personalBudget.changeUserPassword();
                break;
            case '7':
                personalBudget.logOutTheUser();
                break;
            }
        }
    }
    return 0;
}
