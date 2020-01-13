#include "IncomesFile.h"

/*vector <Income> IncomesFile::loadIncomesFromFile() {

    CMarkup xml;
    Income income;
    DateManager dateManager;
    string date;
    int convertDate;
    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ) {

        xml.IntoElem();
        xml.FindElem( "IncomeId" );
        income.setIncomeId( atoi( MCD_2PCSZ(xml.GetData())));

        xml.FindElem( "UserId" );
        income.setUserId( atoi( MCD_2PCSZ(xml.GetData())));

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
    }

    return incomes;
}

void IncomesFile::addIncomeToFile() {
    CMarkup xml;
    string date, item;
    int incomeId, userId;
    float amount;

    DateManager dateManager;
    //date = dateManager.getDateFromTheSystem();
    date = dateManager.enterDate();

    cout << "Podaj  Income ID " << endl;
    cin >> incomeId;
    cout << "Podaj User ID " << endl;
    cin >> userId;
    cout << "Enter Item" << endl;
    cin >> item;
    cout << "Enter Amount";
    cin >> amount;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", incomeId);
    xml.AddElem("UserId", userId);
    xml.AddElem("Date", date);
    xml.AddElem("Item", item);
    xml.AddElem("Amount", amount);

    xml.Save("Incomes.xml");
}

void IncomesFile::showIncomes() {

    for (int i = 0; i < incomes.size(); i++) {
        cout <<incomes[i].getIncomeId() << endl;
        cout <<incomes[i].getUserId() << endl;
        cout <<incomes[i].getDate() << endl;
        cout <<incomes[i].getItem() << endl;
        cout <<incomes[i].getAmount() << endl;

    }
}

//bool IncomesFile:: sortDates(Income income.getDate(), Income income.getDate()) {

  //  return ( income.getDate() < income.getDate() );
//}


void IncomesFile::sortIncomes() {
    //Income income;

    sort(incomes.begin(), incomes.end(), [ ] (const auto& lhs, const auto& rhs) {
        return lhs.date <rhs.date;
    });

    cout << " Posortowany wektor" << endl;

    for (int i = 0; i < incomes.size(); i++) {
        cout <<incomes[i].getIncomeId() << endl;
        cout <<incomes[i].getUserId() << endl;
        cout <<incomes[i].getDate() << endl;
        cout <<incomes[i].getItem() << endl;
        cout <<incomes[i].getAmount() << endl;
    }
}*/
