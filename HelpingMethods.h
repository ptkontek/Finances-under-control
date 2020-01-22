#ifndef HELPINGMETHODS_H
#define HELPINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class HelpingMethods {

public:
    static string convertIntToString(int liczba);
    static int convertStringToInt(string liczba);
    static char loadSign();
    static string loadTheLine();
    static string addDashToDate(string date);
    static string commaToDot(string number);
    static float convertStringToFloat(string number);
    static string convertFloatToString(float number);
    static string uppercaseLetter(string text);
};

#endif
