# include "ExpenseManager.h"

void ExpenseManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<< " << endl << endl;
    expense = writeDataOfTheNewExpense();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);
    cout << endl << "New expense added." << endl;
    system("pause");
}

Expense ExpenseManager::writeDataOfTheNewExpense() {
    Expense expense;
    string item, date, amount;
    float amountWithDot;
    int convertDate;
    DateManager dateManager;
    expense.setExpenseId(expensesFile.getLastExpenseId()+1);
    expense.setUserId(USER_ID);
    cout << "USER ID" << USER_ID << endl;

    date = dateManager.selectDateEntry();

    convertDate = dateManager.convertDateToInt(date);
    expense.setDate(convertDate);

    cout << endl << "-------------------------------" << endl;
    cout <<  "Enter item: ";
    //cin >> item;
    item = HelpingMethods::loadTheLine();
    expense.setItem(item);

    cout << "Enter amount: ";
    cin >> amount;
    amountWithDot = HelpingMethods::convertStringToFloat(HelpingMethods::commaToDot(amount));
    expense.setAmount(amountWithDot);

    return expense;
}

void ExpenseManager::showExpenses() {

    for (int i = 0; i < expenses.size(); i++) {
        cout <<expenses[i].getExpenseId() << endl;
        cout <<expenses[i].getUserId() << endl;
        cout <<expenses[i].getDate() << endl;
        cout <<expenses[i].getItem() << endl;
        cout <<expenses[i].getAmount() << endl;
    }
}

void ExpenseManager::sortExpenses() {
    sort(expenses.begin(), expenses.end(), sortByDate());
}

float ExpenseManager::calculateExpensesFromTheCurrentMonth() {
    DateManager dateManager;
    float sumOfExpenses = 0;
    int dateOfBeginningOfTheCurrentMonth = dateManager.dateOfBeginningOfTheCurrentMonth();
    int dateEndingTheCurrentMonth = dateManager.dateEndingTheCurrentMonth();
    sortExpenses();
    cout << endl;
    for (int i = 0; i < expenses.size(); i++) {
        if ((expenses[i].getDate() >= dateOfBeginningOfTheCurrentMonth) && (expenses[i].getDate() <=dateEndingTheCurrentMonth)) {
            cout << "Expense: " << expenses[i].getAmount() << "  Amount: "<< expenses[i].getItem() << endl;
            sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
        }
    }
    cout << endl << "Sum of expenses from the current month: " << sumOfExpenses << endl << endl;
    cout << "-------------------------------------------" << endl;
    return sumOfExpenses;
}

float ExpenseManager::calculateExpensesFromThePreviousMonth() {
    DateManager dateManager;
    float sumOfExpenses = 0;
    int dateOfBeginningOfThePreviousMonth = dateManager.dateOfBeginningOfThePreviousMonth();
    int dateEndingThePreviousMonth = dateManager.dateEndingThePreviousMonth();
    sortExpenses();
    cout << endl;
    for (int i = 0; i < expenses.size(); i++) {
        if ((expenses[i].getDate() >= dateOfBeginningOfThePreviousMonth) && (expenses[i].getDate() <= dateEndingThePreviousMonth)) {
            cout << "Expense: " << expenses[i].getAmount() << "  Amount: " << expenses[i].getItem() << endl;
            sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
        }
    }
    cout << endl << "Sum of expenses from the previous month: " << sumOfExpenses << endl << endl;
    cout << "-------------------------------------------" << endl;
    return sumOfExpenses;
}

float ExpenseManager::calculateExpensesFromTheTimeInterval(int startDate, int endDate) {
    DateManager dateManager;
    float sumOfExpenses = 0;

    sortExpenses();
    for (int i = 0; i < expenses.size(); i++) {
        if ((expenses[i].getDate() >= startDate) && (expenses[i].getDate() <=endDate)) {
            cout << "Income: " << expenses[i].getAmount() << "  Amount: "<< expenses[i].getItem() << endl;
             sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
        }
    }
    cout << endl << "Sum of expenses from the time interval: " << sumOfExpenses << endl;
    cout << "-------------------------------------------" << endl;
    return sumOfExpenses;
}
