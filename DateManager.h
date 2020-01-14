#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <string>
#include "HelpingMethods.h"
#include <ctime>
#include <conio.h>

using namespace std;

class DateManager {
    int day, month, year, convertDate;
    string date;
    bool checkIfTheDateIsCorrect();


public:
    DateManager() {
    };
    int howManyDaysHasMonth();
    string getDateFromTheSystem();
    string enterDate();
    string getDate();
    int convertDateToInt(string dateString);
    string selectDateEntry();


};




#endif
