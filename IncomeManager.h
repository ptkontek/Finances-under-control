#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "IncomesFile.h"
#include "Markup.h"
#include "HelpingMethods.h"
#include "UserManager.h"
#include <conio.h>

using namespace std;

class IncomeManager {

    const int USER_ID;
    int lastIncomeId;
    vector <Income> incomes;
    UserManager userManager;
    string date;
    Income writeDataOfTheNewIncome();
    void showIncomes();

public:
    IncomeManager (int userId) :
        USER_ID(userId) {
        lastIncomeId = 0;
        incomes = loadIncomesFromFile(USER_ID);

    };
    vector <Income> loadIncomesFromFile(const int USER_ID);
    void addIncomeToFile(Income income);
    void addIncome();
    int getNewIncomeId();
};

#endif
