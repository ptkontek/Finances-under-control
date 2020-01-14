#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <windows.h>
#include <vector>
#include "Income.h"
#include "Markup.h"
#include "DateManager.h"
#include "HelpingMethods.h"

using namespace std;

class IncomesFile {
    int lastIncomeId;
    Income income;
    DateManager dateManager;
    //string date;

public:
    IncomesFile() {
    lastIncomeId = 0;
    };


    vector <Income> loadIncomesFromFile(int userIdAfterLoggedIn);
    void addIncomeToFile(Income income);
    void showIncomes();
    int getLastIncomeId();


    //void sortIncomes();
   /*bool sortDates(Income income.getDate(), Income income.getDate());

    struct sortowanie {
    inline bool operator() (const Income& i, const Income& j) {
        return (k.date < j.date);
    }
    };*/
};

#endif
