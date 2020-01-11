#include "DateManager.h"

int DateManager::howManyDaysHasMonth() {
    int daysInMonth;

    if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        daysInMonth = 30;

    else if (month == 2) {
        if ((year % 4 == 0) && (year % 100 !=0) || (year % 400 == 0)) {
            daysInMonth = 29;
        } else
            daysInMonth = 28;
    } else
        daysInMonth = 31;

    cout << "Days in month: " << month << " is: " << daysInMonth << endl;
    return daysInMonth;
}

string DateManager::getDateFromTheSystem() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);

    string yearString, monthString, dayString;

    year = timeinfo.tm_year+1900;
    month = timeinfo.tm_mon+1;
    day = timeinfo.tm_mday;

    yearString = HelpingMethods::convertIntToString(year);
    if (month < 10)
        monthString = "0" + HelpingMethods::convertIntToString(month);
    else
        monthString = HelpingMethods::convertIntToString(month);
    if (day < 10)
        dayString = "0" + HelpingMethods::convertIntToString(day);
    else
        dayString = HelpingMethods::convertIntToString(day);

    date = (yearString +"-"+ monthString +"-"+ dayString);
    cout << date << endl;

    if (DateManager::checkIfTheDateIsCorrect() == true)
        cout << "Date is correct" << endl;

    return date;
}

string DateManager::enterDate() {

    cout << "Enter date in format yyyy-mm-dd: " << endl;
    cin >> date;

    do {
        year = HelpingMethods::convertStringToInt(date.substr(0,4));
        month = HelpingMethods::convertStringToInt(date.substr(5,2));
        day = HelpingMethods::convertStringToInt(date.substr(8,4));

        if (DateManager::checkIfTheDateIsCorrect() == true)
            cout << "Date is correct" << endl;
        else {
            cout << "Date isn't correct. Enter date again in format yyyy-mm-dd: " << endl;
            cin >> date;
        }
    } while (DateManager::checkIfTheDateIsCorrect() == false);

    return date;
}

int DateManager::convertDateToInt(string dateString) {
    convertDate = HelpingMethods::convertStringToInt(dateString.substr(0,4)+ dateString.substr(5,2) + dateString.substr(8,4));
    cout << convertDate << endl << endl;
    return convertDate;
}

bool DateManager::checkIfTheDateIsCorrect() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);

    if (date.length() != 10)
        return false;

    for (int i = 0; i < 10; i++) {
        if ((i==4) || (i==7)) {
            if (date[i] != '-')
                return false;
        }
    }

    if (year == (timeinfo.tm_year+1900)) {
        if ((month > 0) && (month <= timeinfo.tm_mon+1)) {
            if ((day > 0 ) && (day <= timeinfo.tm_mday))
                return true;
            else
                return false;
        } else
            return false;

    } else if ((year >= 2000) && (year <= timeinfo.tm_year+1900)) {

        if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
            if ((day > 0) && (day <= 30))
                return true;
            else
                return false;

        } else if (month == 2) {
            if ((year % 4 == 0) && (year % 100 !=0) || (year % 400 == 0)) {
                if ((day > 0) && (day <= 29))
                    return true;
                else if ((day > 0) && (day <= 28))
                    return true;
                else if (day > 29)
                    return false;
            }
        } else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {

            if ((day > 0) && (day <= 31))
                return true;
            else
                return false;

        } else if (month > 12)
            return false;

    } else if ((year < 2000) && (year > timeinfo.tm_year+1900))
        return false;
}
