# include "IncomeManager.h"

void IncomeManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<< " << endl << endl;
    income = writeDataOfTheNewIncome();

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
    cout << endl << "New income added." << endl;

    showIncomes();
    system("pause");
}

Income IncomeManager::writeDataOfTheNewIncome() {
    Income income;
    string item, date;
    float amount;
    int convertDate;
    DateManager dateManager;
    income.setIncomeId(incomesFile.getLastIncomeId()+1);
    income.setUserId(USER_ID);
    cout << "USER ID" << USER_ID << endl;

    date = dateManager.selectDateEntry();

    convertDate = dateManager.convertDateToInt(date);
    income.setDate(convertDate);

    cout << "Enter item: ";
    //item = HelpingMethods::loadTheLine();
    cin >> item;
    income.setItem(item);

    cout << "Enter amount: ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}



void IncomeManager::showIncomes() {

    for (int i = 0; i < incomes.size(); i++) {
        cout <<incomes[i].getIncomeId() << endl;
        cout <<incomes[i].getUserId() << endl;
        cout <<incomes[i].getDate() << endl;
        cout <<incomes[i].getItem() << endl;
        cout <<incomes[i].getAmount() << endl;
    }
}
