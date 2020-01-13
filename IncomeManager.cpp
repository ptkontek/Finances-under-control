# include "IncomeManager.h"

void IncomeManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<< " << endl << endl;
    income = writeDataOfTheNewIncome();

    incomes.push_back(income);
    addIncomeToFile(income);
    cout << endl << "New income added." << endl;

    showIncomes();
    system("pause");
}

Income IncomeManager::writeDataOfTheNewIncome() {
    Income income;
    string item;
    float amount;
    int convertDate;
    DateManager dateManager;
    income.setIncomeId(getNewIncomeId());
    income.setUserId(USER_ID);
    cout << "USER ID" << USER_ID << endl;

    char sign;
    cout << "If you want do add today's income - enter 1, if not - enter 2 to set the date:";

    do {
        sign = getch();
        if ( (sign != '1') && (sign !='2') )
            cout << "Enter 1 or 2" << endl;
    } while ( (sign != '1') && (sign !='2') );


    if (sign == '1')
        date = dateManager.getDateFromTheSystem();
    else if (sign == '2')
        date = dateManager.enterDate();

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

int IncomeManager::getNewIncomeId() {
        return lastIncomeId + 1;

}

vector <Income> IncomeManager::loadIncomesFromFile(const int USER_ID) {

    CMarkup xml;
    Income income;
    DateManager dateManager;
    int convertDate;
    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ) {

        xml.IntoElem();
        xml.FindElem( "UserId" );
        if (USER_ID == (atoi( MCD_2PCSZ(xml.GetData())))) {

            xml.ResetMainPos();
            xml.FindElem( "IncomeId" );
            income.setIncomeId( atoi( MCD_2PCSZ(xml.GetData())));
            lastIncomeId = atoi( MCD_2PCSZ(xml.GetData()));

            xml.FindElem( "UserId" );
            income.setUserId(USER_ID);

            xml.FindElem( "Date" );
            date = (xml.GetData());
            convertDate = dateManager.convertDateToInt(date);
            income.setDate(convertDate);

            xml.FindElem( "Item" );
            income.setItem(xml.GetData());

            xml.FindElem( "Amount" );
            income.setAmount( atoi( MCD_2PCSZ(xml.GetData())));

            incomes.push_back(income);

            xml.OutOfElem();
        } else {
            xml.FindElem( "IncomeId" );
            lastIncomeId = atoi( MCD_2PCSZ(xml.GetData()));
        }
    }

    return incomes;
}

void IncomeManager::addIncomeToFile(Income income) {
    CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", getNewIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", date);
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save("Incomes.xml");
    lastIncomeId++;
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
