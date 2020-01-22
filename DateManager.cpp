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

    return daysInMonth;
}

int DateManager::getMonthFromTheSystem() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);
    month = timeinfo.tm_mon+1;
    return month;
}
int DateManager::getYearFromTheSystem() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);
    year = timeinfo.tm_year+1900;
    return year;
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
    if (DateManager::checkIfTheDateIsCorrect() == true)
        return date;
}

int DateManager::dateOfBeginningOfTheCurrentMonth() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);

    string yearString, monthString, dayString;
    int dateOfBeginningOfTheCurrentMonth;
    year = timeinfo.tm_year+1900;
    month = timeinfo.tm_mon+1;
    day = 1;

    yearString = HelpingMethods::convertIntToString(year);
    dayString = "0" + HelpingMethods::convertIntToString(day);
    if (month < 10)
        monthString = "0" + HelpingMethods::convertIntToString(month);
    else
        monthString = HelpingMethods::convertIntToString(month);

    date = (yearString + monthString + dayString);
    dateOfBeginningOfTheCurrentMonth = HelpingMethods::convertStringToInt(date);
    return dateOfBeginningOfTheCurrentMonth;
}

int DateManager::dateEndingTheCurrentMonth() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);

    string yearString, monthString, dayString;
    int dateEndingTheCurrentMonth;
    year = timeinfo.tm_year+1900;
    month = timeinfo.tm_mon+1;
    day = howManyDaysHasMonth();

    yearString = HelpingMethods::convertIntToString(year);
    dayString = HelpingMethods::convertIntToString(day);
    if (month < 10)
        monthString = "0" + HelpingMethods::convertIntToString(month);
    else
        monthString = HelpingMethods::convertIntToString(month);

    date = (yearString + monthString + dayString);
    dateEndingTheCurrentMonth = HelpingMethods::convertStringToInt(date);
    return dateEndingTheCurrentMonth;
}

int DateManager::dateOfBeginningOfThePreviousMonth() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);

    string yearString, monthString, dayString;
    int dateOfBeginningOfThePreviousMonth;
    year = timeinfo.tm_year+1900;
    month = timeinfo.tm_mon+1;

    if (month == 1) {
        month = 12;
        year = year-1;
    } else
        month = month-1;
    day = 1;

    if (month < 10)
        monthString = "0" + HelpingMethods::convertIntToString(month);
    else if ((month >= 10) && (month <= 12))
        monthString = HelpingMethods::convertIntToString(month);

    yearString = HelpingMethods::convertIntToString(year);
    dayString = "0" + HelpingMethods::convertIntToString(day);

    date = (yearString + monthString + dayString);
    dateOfBeginningOfThePreviousMonth = HelpingMethods::convertStringToInt(date);
    return dateOfBeginningOfThePreviousMonth;
}

int DateManager::dateEndingThePreviousMonth() {
    time_t czas;
    tm timeinfo;
    time (&czas);
    timeinfo = *localtime( &czas);

    string yearString, monthString, dayString;
    int dateEndingThePreviousMonth;
    year = timeinfo.tm_year+1900;
    month = timeinfo.tm_mon+1;

    if (month == 1) {
        month = 12;
        year = year-1;
    } else
        month = month-1;

    day = howManyDaysHasMonth();

    if (month < 10) {
        monthString = "0" + HelpingMethods::convertIntToString(month);
        if (month == 1)
            year = year-1;
    } else if ((month >= 10) && (month <= 12))
        monthString = HelpingMethods::convertIntToString(month);

    yearString = HelpingMethods::convertIntToString(year);
    dayString = HelpingMethods::convertIntToString(day);

    date = (yearString + monthString + dayString);
    dateEndingThePreviousMonth = HelpingMethods::convertStringToInt(date);
    return dateEndingThePreviousMonth;
}

string DateManager::enterDate() {

    cout << endl << "Enter date in format yyyy-mm-dd: ";
    cin >> date;

    do {
        year = HelpingMethods::convertStringToInt(date.substr(0,4));
        month = HelpingMethods::convertStringToInt(date.substr(5,2));
        day = HelpingMethods::convertStringToInt(date.substr(8,2));

        if (DateManager::checkIfTheDateIsCorrect() != true) {
            cout << endl << "Date isn't correct. Enter date again in format yyyy-mm-dd: ";
            cin >> date;
        }
    } while (DateManager::checkIfTheDateIsCorrect() != true);

        return date;
}

string DateManager::selectDateEntry() {
    char sign;
    cout << "If you want do add today's income - enter 1" << endl << "if not - enter 2 to set the date: ";

    do {
        sign = getch();
        if ( (sign != '1') && (sign !='2') )
            cout << "Enter 1 or 2" << endl;
    } while ( (sign != '1') && (sign !='2') );


    if (sign == '1')
        date = getDateFromTheSystem();
    else if (sign == '2')
        date = enterDate();

    return date;
}

int DateManager::convertDateToInt(string dateString) {
    convertDate = HelpingMethods::convertStringToInt(dateString.substr(0,4)+ dateString.substr(5,2) + dateString.substr(8,4));
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
            } else if ((day > 0) && (day <= 28))
                return true;
            else if (day > 29)
                return false;

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
