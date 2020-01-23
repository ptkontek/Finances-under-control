#include "HelpingMethods.h"

string HelpingMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelpingMethods::convertFloatToString(float number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int HelpingMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

float HelpingMethods::convertStringToFloat(string number) {
    float numberFloat;
    stringstream ss;
    ss << number;
    ss >> numberFloat;
    return numberFloat;
}

string HelpingMethods::addDashToDate(string date) {
    string month, day, year, dateWithDash;

    year = date.substr(0,4);
    month = (date.substr(4,2));
    day = (date.substr(6,2));

    dateWithDash = (year +"-"+ month +"-"+ day);

    return  dateWithDash;
}

char HelpingMethods::loadSign() {
    string start = "";
    char sign  = {0};

    while (true) {
        getline(cin, start);

        if (start.length() == 1) {
            sign = start[0];
            break;
        }
        cout << "This is not a single sign. Enter again." << endl;
    }
    return sign;
}

string HelpingMethods::commaToDot(string number) {
    for (int i=0; i<number.size(); i++) {
        if (number[i] == ',') {
            number[i] = '.';
            break;
        } else
            number[i] == number[i];
    }
    return number;
}

string HelpingMethods::loadTheLine() {
    cin.clear();
    cin.sync();
    string start = "";
    getline(cin, start);
    return start;
}

string HelpingMethods::uppercaseLetter(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
