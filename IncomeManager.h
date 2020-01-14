#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "IncomesFile.h"
#include "Markup.h"
#include "HelpingMethods.h"
#include "UserManager.h"


using namespace std;

class IncomeManager {

    const int USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;

    Income writeDataOfTheNewIncome();
    void showIncomes();

public:
    IncomeManager (int userId) :
        USER_ID(userId) {
        incomes = incomesFile.loadIncomesFromFile(USER_ID);
    };
    void addIncome();
};

#endif
