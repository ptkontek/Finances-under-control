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
    } else
        cout << "To add income you have to log in" << endl;
}

void PersonalBudget::addExpense() {
    if (userManager.isTheUserLoggedIn()) {
        expenseManager->addExpense();
    }else
        cout << "To add expense you have to log in" << endl;
}

void PersonalBudget::calculateFinancesFromTheCurrentMonth() {
    float sumOfIncomes, sumOfExpenses, sumDiferrence;

    sumOfIncomes = incomeManager->calculateIncomesFromTheCurrentMonth();
    sumOfExpenses = expenseManager->calculateExpensesFromTheCurrentMonth();
    sumDiferrence = sumOfIncomes - sumOfExpenses;

    if (sumDiferrence > 0 )
        cout << "Your savings from the current month: " << sumDiferrence << endl << endl;
    else if (sumDiferrence < 0)
        cout << "Your debt from the current month: " << -sumDiferrence << endl << endl;
    else if (sumDiferrence == 0)
        cout << "You have no savings or debt." << endl << endl;
    system("pause");
}

void PersonalBudget::calculateFinancesFromThePreviousMonth() {
    float sumOfIncomes, sumOfExpenses, sumDiferrence;

    sumOfIncomes = incomeManager->calculateIncomesFromThePreviousMonth();
    sumOfExpenses = expenseManager->calculateExpensesFromThePreviousMonth();
    sumDiferrence = sumOfIncomes - sumOfExpenses;

    if (sumDiferrence > 0 )
        cout << "Your savings from the previous month: " << sumDiferrence << endl << endl;
    else if (sumDiferrence < 0)
        cout << "Your debt from the previous month: " << -sumDiferrence << endl << endl;
    else if (sumDiferrence == 0)
        cout << "You have no savings or debt." << endl << endl;
    system("pause");
}

void PersonalBudget::calculateFinancesFromTheTimeInterval() {
    float sumOfIncomes, sumOfExpenses, sumDiferrence, startDate, endDate;
    DateManager dateManager;

    cout << "What period do you want to get the finance balance? " << endl;
    cout << endl << "START DATE" << endl;
    startDate = dateManager.convertDateToInt(dateManager.enterDate());
    cout << endl << "END DATE" << endl;
    endDate = dateManager.convertDateToInt(dateManager.enterDate());

    sumOfIncomes = incomeManager->calculateIncomesFromTheTimeInterval(startDate, endDate);
    sumOfExpenses = expenseManager->calculateExpensesFromTheTimeInterval(startDate, endDate);
    sumDiferrence = sumOfIncomes - sumOfExpenses;

    if (sumDiferrence > 0 )
        cout << "Your savings from the time interval: " << sumDiferrence << endl << endl;
    else if (sumDiferrence < 0)
        cout << "Your debt from the time interval: " << -sumDiferrence << endl << endl;
    else if (sumDiferrence == 0)
        cout << "You have no savings or debt." << endl << endl;
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
