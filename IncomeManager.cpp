# include "IncomeManager.h"

void IncomeManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<< " << endl << endl;
    income = writeDataOfTheNewIncome();

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
    cout << endl << "New income added." << endl;
    system("pause");
}

Income IncomeManager::writeDataOfTheNewIncome() {
    Income income;
    string item, date, amount;
    float amountWithDot;
    int convertDate;
    DateManager dateManager;
    income.setIncomeId(incomesFile.getLastIncomeId()+1);
    income.setUserId(USER_ID);
    cout << "USER ID" << USER_ID << endl;

    date = dateManager.selectDateEntry();

    convertDate = dateManager.convertDateToInt(date);
    income.setDate(convertDate);

    cout << endl << "-------------------------------" << endl;
    cout << "Enter item: ";
    //cin >> item;
    item = HelpingMethods::loadTheLine();
    income.setItem(item);


    cout << "Enter amount: ";
    cin >> amount;

    amountWithDot = HelpingMethods::convertStringToFloat(HelpingMethods::commaToDot(amount));
    income.setAmount(amountWithDot);

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
    system("pause");
}

void IncomeManager::sortIncomes() {
    sort(incomes.begin(), incomes.end(), sortByDate());
}

float IncomeManager::calculateIncomesFromThePreviousMonth() {
    DateManager dateManager;
    float sumOfIncomes = 0;
    int dateOfBeginningOfThePreviousMonth = dateManager.dateOfBeginningOfThePreviousMonth();
    int dateEndingThePreviousMonth = dateManager.dateEndingThePreviousMonth();
    sortIncomes();
    cout << endl << "-------------------------------------------" << endl;
    cout << "Finances from the previous month: " << endl <<endl;
    for (int i = 0; i < incomes.size(); i++) {
        if ((incomes[i].getDate() >= dateOfBeginningOfThePreviousMonth) && (incomes[i].getDate() <=dateEndingThePreviousMonth)) {
            cout << "Income: " << incomes[i].getAmount() << "  Amount: "<< incomes[i].getItem() << endl;
            sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
        }
    }
    cout << endl << "Sum of incomes from the previous month: " << sumOfIncomes << endl;
    cout << "-------------------------------------------" << endl;
    return sumOfIncomes;
}

float IncomeManager::calculateIncomesFromTheCurrentMonth() {
    DateManager dateManager;
    float sumOfIncomes = 0;
    int dateOfBeginningOfTheCurrentMonth = dateManager.dateOfBeginningOfTheCurrentMonth();
    int dateEndingTheCurrentMonth = dateManager.dateEndingTheCurrentMonth();

    sortIncomes();
    cout << endl << "-------------------------------------------" << endl;
    cout << "Finances from the current month: " << endl <<endl;
    for (int i = 0; i < incomes.size(); i++) {
        if ((incomes[i].getDate() >= dateOfBeginningOfTheCurrentMonth) && (incomes[i].getDate() <= dateEndingTheCurrentMonth)) {
            cout << "Income: " << incomes[i].getAmount() << "  Amount: "<< incomes[i].getItem() << endl;
            sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
        }
    }
    cout << endl << "Sum of incomes from the current month: " << sumOfIncomes << endl;
    cout << "-------------------------------------------" << endl;
    return sumOfIncomes;
}

float IncomeManager::calculateIncomesFromTheTimeInterval(int startDate, int endDate) {
    DateManager dateManager;
    float sumOfIncomes = 0;

    sortIncomes();
    cout << endl << "-------------------------------------------" << endl;
    cout << "Finances from the time interval: " << endl <<endl;
    for (int i = 0; i < incomes.size(); i++) {
        if ((incomes[i].getDate() >= startDate) && (incomes[i].getDate() <= endDate)) {
            cout << "Income: " << incomes[i].getAmount() << "  Amount: "<< incomes[i].getItem() << endl;
            sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
        }
    }
    cout << endl << "Sum of incomes from the time interval: " << sumOfIncomes << endl;
    cout << "-------------------------------------------" << endl;
    return sumOfIncomes;
}
