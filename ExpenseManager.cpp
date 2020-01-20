# include "ExpenseManager.h"

void ExpenseManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<< " << endl << endl;
    expense = writeDataOfTheNewExpense();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);
    cout << endl << "New expense added." << endl;

    showExpenses();
    system("pause");
}

Expense ExpenseManager::writeDataOfTheNewExpense() {
    Expense expense;
    string item, date;
    float amount;
    int convertDate;
    DateManager dateManager;
    expense.setExpenseId(expensesFile.getLastExpenseId()+1);
    expense.setUserId(USER_ID);
    cout << "USER ID" << USER_ID << endl;

    date = dateManager.selectDateEntry();

    convertDate = dateManager.convertDateToInt(date);
    expense.setDate(convertDate);

    cout << "Enter item: ";
    cin >> item;
    expense.setItem(item);

    cout << "Enter amount: ";
    cin >> amount;
    expense.setAmount(amount);

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

int ExpenseManager::calculateExpensesFromTheCurrentMonth() {
    DateManager dateManager;
    int sumOfExpenses = 0;
    int dateOfBeginningOfTheCurrentMonth = dateManager.dateOfBeginningOfTheCurrentMonth();
    int dateEndingTheCurrentMonth = dateManager.dateEndingTheCurrentMonth();
    sortExpenses();
    cout << endl;
    for (int i = 0; i < expenses.size(); i++) {
        if ((expenses[i].getDate() >= dateOfBeginningOfTheCurrentMonth) && (expenses[i].getDate() <=dateEndingTheCurrentMonth)){
            cout << "Expense: " << expenses[i].getAmount() << "  Amount: "<< expenses[i].getItem() << endl;
   sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
    }
    }
    cout << "Sum of expenses from the current month: " << sumOfExpenses << endl << endl;
    return sumOfExpenses;
}
