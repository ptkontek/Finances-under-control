#ifndef HELPINGMETHODS_H
#define HELPINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelpingMethods {

public:
    static string convertIntToString(int liczba);
    static int convertStringToInt(string liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static char wczytajZnak();
    static string wczytajLinie();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
};


#endif
