#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "Markup.h"
#include "DateManager.h"

using namespace std;

class IncomesFile {
    vector <Income> incomes;
    Income income;

public:
    IncomesFile() {};
    vector <Income> loadIncomesFromFile();
    void addIncomeToFile();
    void showIncomes();
    void sortIncomes();
   // bool sortDates(Income income.getDate(), Income income.getDate());

    /*struct sortowanie {
    inline bool operator() (const Income& i, const Income& j) {
        return (k.date < j.date);
    }
    };*/
};

#endif
