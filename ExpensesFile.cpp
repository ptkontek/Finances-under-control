#include "ExpensesFile.h"

vector <Expense> ExpensesFile::loadExpensesFromFile(int userIdAfterLoggedIn) {

    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    int convertDate;
    string date;
    bool fileExists = xml.Load( "Expenses.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") ) {

        xml.IntoElem();
        xml.FindElem( "UserId" );
        if (userIdAfterLoggedIn == (atoi( MCD_2PCSZ(xml.GetData())))) {

            xml.ResetMainPos();
            xml.FindElem( "ExpenseId" );
            expense.setExpenseId( atoi( MCD_2PCSZ(xml.GetData())));
            lastExpenseId = atoi( MCD_2PCSZ(xml.GetData()));

            xml.FindElem( "UserId" );
            expense.setUserId(userIdAfterLoggedIn);

            xml.FindElem( "Date" );
            date = (xml.GetData());
            convertDate = dateManager.convertDateToInt(date);
            expense.setDate(convertDate);

            xml.FindElem( "Item" );
            expense.setItem(xml.GetData());

            xml.FindElem( "Amount" );
            expense.setAmount( atoi( MCD_2PCSZ(xml.GetData())));

            expenses.push_back(expense);

            xml.OutOfElem();
        } else {
            xml.ResetMainPos();
            xml.FindElem( "ExpenseId" );
            lastExpenseId = atoi( MCD_2PCSZ(xml.GetData()));
            xml.OutOfElem();
        }
    }

    return expenses;
}

void ExpensesFile::addExpenseToFile(Expense expense) {
    CMarkup xml;
    bool fileExists = xml.Load( "Expenses.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }


    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", getLastExpenseId()+1);
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", dateManager.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save("Expenses.xml");
    lastExpenseId++;
}

int ExpensesFile::getLastExpenseId() {
        return lastExpenseId;
}
