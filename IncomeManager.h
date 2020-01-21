#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
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

    struct sortByDate {
        inline bool operator()( Income& struct1,  Income& struct2) {
            return (struct1.getDate() < struct2.getDate());
        }
    };


public:
    IncomeManager (int userId) :
        USER_ID(userId) {
        incomes = incomesFile.loadIncomesFromFile(USER_ID);
    };
    void addIncome();
    void sortIncomes();
    int calculateIncomesFromThePreviousMonth();
    int calculateIncomesFromTheCurrentMonth();
    int calculateIncomesFromTheTimeInterval(int startDate, int endDate);
};

#endif
