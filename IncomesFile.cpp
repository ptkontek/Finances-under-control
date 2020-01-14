#include "IncomesFile.h"

vector <Income> IncomesFile::loadIncomesFromFile(int userIdAfterLoggedIn) {

    CMarkup xml;
    Income income;
    vector <Income> incomes;
    int convertDate;
    string date;
    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ) {

        xml.IntoElem();
        xml.FindElem( "UserId" );
        if (userIdAfterLoggedIn == (atoi( MCD_2PCSZ(xml.GetData())))) {

            xml.ResetMainPos();
            xml.FindElem( "IncomeId" );
            income.setIncomeId( atoi( MCD_2PCSZ(xml.GetData())));
            lastIncomeId = atoi( MCD_2PCSZ(xml.GetData()));

            xml.FindElem( "UserId" );
            income.setUserId(userIdAfterLoggedIn);

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

void IncomesFile::addIncomeToFile(Income income) {
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
    xml.AddElem("IncomeId", getLastIncomeId()+1);
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", dateManager.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save("Incomes.xml");
    lastIncomeId++;
}

int IncomesFile::getLastIncomeId() {
        return lastIncomeId;
}

/*bool IncomesFile:: sortDates(Income income.getDate(), Income income.getDate()) {

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
