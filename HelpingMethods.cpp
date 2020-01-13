#include "HelpingMethods.h"

string HelpingMethods::convertIntToString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int HelpingMethods::convertStringToInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
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

string HelpingMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

string HelpingMethods::loadTheLine() {
    string start = "";
    getline(cin, start);
    return start;
}

string HelpingMethods::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int HelpingMethods::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

