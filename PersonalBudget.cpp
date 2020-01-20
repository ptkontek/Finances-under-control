# include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogin() {
    userManager.userLogin();
    if (userManager.isTheUserLoggedIn()) {
        incomeManager = new IncomeManager(userManager.getUserIdAfterLoggedIn());
        expenseManager = new ExpenseManager(userManager.getUserIdAfterLoggedIn());
    }
}

bool PersonalBudget::isTheUserLoggedIn() {
    userManager.isTheUserLoggedIn();
}

void PersonalBudget::logOutTheUser() {
    userManager.logOutTheUser();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
}

void PersonalBudget::changeUserPassword() {
    userManager.changeUserPassword();
}

void PersonalBudget::addIncome() {
    if (userManager.isTheUserLoggedIn()) {
        incomeManager->addIncome();
    }
    incomeManager->addIncome();
}

void PersonalBudget::addExpense() {
    if (userManager.isTheUserLoggedIn()) {
        expenseManager->addExpense();
    }
    expenseManager->addExpense();
}

void PersonalBudget::sortIncomes() {
    incomeManager->sortIncomes();
}

void PersonalBudget::calculateIncomesFromTheCurrentMonth() {
    int sumOfIncomes, sumOfExpenses, sumDiferrence;
    sumOfIncomes = incomeManager->calculateIncomesFromTheCurrentMonth();
    sumOfExpenses = expenseManager->calculateExpensesFromTheCurrentMonth();
    sumDiferrence = sumOfIncomes - sumOfExpenses;
    if (sumDiferrence > 0 )
        cout << "Your savings from the current month: " << sumDiferrence << endl;
    else if (sumDiferrence < 0)
        cout << "Your debt from the current month: " << -sumDiferrence << endl;
    else if (sumDiferrence == 0)
        cout << "You have no savings or debt." << endl;
    system("pause");
}


char PersonalBudget::selectOptionFromTheMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User registration" << endl;
    cout << "2. User login" << endl;
    cout << "9. End of program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelpingMethods::loadSign();

    return choice;
}

char PersonalBudget::selectOptionFromTheUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance of finances from the current month" << endl;
    cout << "4. Balance of finances from the previous month" << endl;
    cout << "5. Balance of finances from the time interval" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change user password" << endl;
    cout << "7. Log out the user" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelpingMethods::loadSign();

    return choice;
}
