#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int const col = 13, row = 16;

void wypisz(char tab[col][row]) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

string haslo(char tab[col][row]) {
    string wynik;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (!(tab[i][j] == ' '))
                wynik += tab[i][j];
        }
    }
    return wynik;
}

void kopiuj(char tab1[col][row], char tab2[col][row]) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            tab2[i][j] = tab1[i][j];
        }
    }
}

void wymarz(char tab[col][row], vector<int> wartosci) {
    for (int i = 1; i < wartosci.size(); i++) {
        tab[wartosci[0]][wartosci[i]] = ' ';
    }
}

string odwrot(string tekst) {
    string wynik;
    char temp;
    for (int i = tekst.size()-1; i >= 0; i--) {
        temp = tekst[i];
        wynik += temp;
    }
    return wynik;
}

void znajdz(char tab[col][row], vector<string> hasla) {
    char temp[col][row], wynik[col][row];
    kopiuj(tab, temp);
    kopiuj(tab, wynik);
    for (int s = 0; s < hasla.size(); s++) {
        string slowo = hasla[s];
        vector<int> wspolrzedne;
        string slowo_odwrotne;
        slowo_odwrotne = odwrot(slowo);
        int z = 0;
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                //poziomo
                if (temp[i][j] == slowo[0]) {
                    wspolrzedne.push_back(i);
                    wspolrzedne.push_back(j);
                    for (int k = 1; k < slowo.size(); k++) {
                        j++;
                        if (!(temp[i][j] == slowo[k])) {
                            j -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(j);
                        }
                    }
                    if (wspolrzedne.size() == slowo.size() + 1) {
                        for (int k = 1; k < slowo.size() + 1; k++) {
                            wynik[wspolrzedne[0]][wspolrzedne[k]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
                //poziomo od tyłu
                if (temp[i][j] == slowo_odwrotne[0]) {
                    wspolrzedne.push_back(i);
                    wspolrzedne.push_back(j);
                    for (int k = 1; k < slowo_odwrotne.size(); k++) {
                        j++;
                        if (!(temp[i][j] == slowo_odwrotne[k])) {
                            j -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(j);
                        }
                    }
                    if (wspolrzedne.size() == slowo_odwrotne.size() + 1) {
                        for (int k = 1; k < slowo_odwrotne.size() + 1; k++) {
                            wynik[wspolrzedne[0]][wspolrzedne[k]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
                //pionowo
                if (temp[i][j] == slowo[0]) {
                    wspolrzedne.push_back(j);
                    wspolrzedne.push_back(i);
                    for (int k = 1; k < slowo.size(); k++) {
                        i++;
                        if (!(temp[i][j] == slowo[k])) {
                            i -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(i);
                        }
                    }
                    if (wspolrzedne.size() == slowo.size() + 1) {
                        for (int k = 1; k < slowo.size() + 1; k++) {
                            wynik[wspolrzedne[k]][wspolrzedne[0]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
                //pionowo od tyłu
                if (temp[i][j] == slowo_odwrotne[0]) {
                    wspolrzedne.push_back(j);
                    wspolrzedne.push_back(i);
                    for (int k = 1; k < slowo_odwrotne.size(); k++) {
                        i++;
                        if (!(temp[i][j] == slowo_odwrotne[k])) {
                            i -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(i);
                        }
                    }
                    if (wspolrzedne.size() == slowo_odwrotne.size() + 1) {
                        for (int k = 1; k < slowo_odwrotne.size() + 1; k++) {
                            wynik[wspolrzedne[k]][wspolrzedne[0]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
                //skos (lewo-dół)
                if (temp[i][j] == slowo[0]) {
                    wspolrzedne.push_back(i);
                    wspolrzedne.push_back(j);
                    int z = i;
                    for (int k = 1; k < slowo.size(); k++) {
                        z++;
                        j++;
                        if (!(temp[z][j] == slowo[k])) {
                            z -= k;
                            j -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(z);
                            wspolrzedne.push_back(j);
                        }
                    }
                    if (wspolrzedne.size() == (2 * slowo.size())) {
                        for (int k = 0; k < slowo.size()*2; k+=2) {
                            wynik[wspolrzedne[k]][wspolrzedne[k+1]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
                //skos od tyłu (lewo-dół)
                if (temp[i][j] == slowo_odwrotne[0]) {
                    wspolrzedne.push_back(i);
                    wspolrzedne.push_back(j);
                    int z = i;
                    for (int k = 1; k < slowo_odwrotne.size(); k++) {
                        z++;
                        j++;
                        if (!(temp[z][j] == slowo_odwrotne[k])) {
                            z -= k;
                            j -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(z);
                            wspolrzedne.push_back(j);
                        }
                    }
                    if (wspolrzedne.size() == (2 * slowo_odwrotne.size())) {
                        for (int k = 0; k < slowo_odwrotne.size() * 2; k += 2) {
                            wynik[wspolrzedne[k]][wspolrzedne[k + 1]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
                //skos (prawo-góra)
                if (temp[i][j] == slowo[0]) {
                    wspolrzedne.push_back(i);
                    wspolrzedne.push_back(j);
                    int z = i;
                    for (int k = 1; k < slowo.size(); k++) {
                        z--;
                        j++;
                        if (!(temp[z][j] == slowo[k])) {
                            z += k;
                            j -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(z);
                            wspolrzedne.push_back(j);
                        }
                    }
                    if (wspolrzedne.size() == (2 * slowo.size())) {
                        for (int k = 0; k < slowo.size() * 2; k += 2) {
                            wynik[wspolrzedne[k]][wspolrzedne[k + 1]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
                //skos od tyłu (prawo-góra)
                if (temp[i][j] == slowo_odwrotne[0]) {
                    wspolrzedne.push_back(i);
                    wspolrzedne.push_back(j);
                    int z = i;
                    for (int k = 1; k < slowo_odwrotne.size(); k++) {
                        z--;
                        j++;
                        if (!(temp[z][j] == slowo_odwrotne[k])) {
                            z += k;
                            j -= k;
                            break;
                        }
                        else {
                            wspolrzedne.push_back(z);
                            wspolrzedne.push_back(j);
                        }
                    }
                    if (wspolrzedne.size() == (2 * slowo_odwrotne.size())) {
                        for (int k = 0; k < slowo_odwrotne.size() * 2; k += 2) {
                            wynik[wspolrzedne[k]][wspolrzedne[k + 1]] = ' ';
                        }
                    }
                }
                wspolrzedne.clear();
            }
        }
    }
    kopiuj(wynik, tab);
}

int main()
{
    char tab[col][row];
    string temp;
    int i = 0;
    ifstream tekst("wykreslanka.txt");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (!(tekst >> tab[i][j])) {
                cout << "Błąd odczytu danych" << endl;
                return 1;
            }
        }
    }
    tekst.close();

    ifstream hasla("hasla.txt");
    vector<string> slowa;
    string word;
    char litera;
    while (!hasla.eof()) {
        hasla >> litera;
        if (!(litera == ';')) {
            word += litera;
        }
        else {
            slowa.push_back(word);
            word.clear();
        }
    }

    wypisz(tab);

    cout << endl;

    znajdz(tab, slowa);

    wypisz(tab);

    cout << "Haslo: " << haslo(tab) << endl;
    
}