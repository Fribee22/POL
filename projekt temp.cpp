#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;
double historiaWartosci[MAX_SIZE] = { 0.0 };
char historiaJednostek[MAX_SIZE] = { 0 };
int dataCounter = 0;

float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);
float check(float temp, char stopnie);

double wczytajLiczbe();
void dodajDoHistorii(float wejscie, char skalaWej, float wyjscie, char skalaWyj);
void pokazHistorie();
void usunZHistorii();
void modyfikujHistorie();
void wypelnijLosowo();
float przeliczOgolem(float temp, char z, char na);

int main() {
    srand(time(NULL));
    int wybor;

    while (true) {
        system("cls"); 
        cout << "\n=== MENU GLOWNE ===" << endl;
        cout << "1. przelicz Fahr na Celsius \n";
        cout << "2. przelicz Fahr na Kelwin \n";
        cout << "3. przelicz Celsius na Fahr \n";
        cout << "4. przelicz Celsius na Kelwin\n";
        cout << "5. przelicz Kelwin na Fahr \n";
        cout << "6. przelicz Kelwin na Celsius \n";
        cout << "7. KONIEC PROGRAMU \n";
        cout << "8. Pokaz historie (Filtrowanie) \n"; 
        cout << "9. Usun wpis z historii \n";
        cout << "10. Modyfikuj wpis z historii \n";
        cout << "11. Losowe wypelnienie historii \n";
        cout << "=================================" << endl;

        cout << "Wybierz opcje: ";
        wybor = (int)wczytajLiczbe(); 

        if (wybor == 7) {
            return 0;
        }
        else if (wybor == 8) {
            pokazHistorie();
        }
        else if (wybor == 9) {
            usunZHistorii();
        }
        else if (wybor == 10) {
            modyfikujHistorie();
        }
        else if (wybor == 11) {
            wypelnijLosowo();
        }
        else if (wybor >= 1 && wybor <= 6) {
            cout << "Podaj temperature do przeliczenia: ";
            float stopnie = (float)wczytajLiczbe();

            char skalaWejsciowa, skalaWynikowa;
            
            if (wybor == 1 || wybor == 2) skalaWejsciowa = 'F';
            else if (wybor == 3 || wybor == 4) skalaWejsciowa = 'C';
            else skalaWejsciowa = 'K';

            if (wybor == 1 || wybor == 6) skalaWynikowa = 'C';
            else if (wybor == 2 || wybor == 4) skalaWynikowa = 'K';
            else skalaWynikowa = 'F';

            float wynikCheck = check(stopnie, skalaWejsciowa);

            if (wynikCheck == -999.0f) {
                cout << "\nBLAD: Nie ma takiej temperatury (ponizej zera absolutnego)!" << endl;
                cout << "\nNacisnij ENTER aby kontynuowac...";
                cin.ignore(); cin.get();
            }
            else {
                float wynik = przeliczOgolem(stopnie, skalaWejsciowa, skalaWynikowa);

                cout << "\nWynik: " << stopnie << " " << skalaWejsciowa
                     << " = " << wynik << " " << skalaWynikowa << endl;

                dodajDoHistorii(stopnie, skalaWejsciowa, wynik, skalaWynikowa);
                
                cout << "\nNacisnij ENTER aby kontynuowac...";
                cin.ignore(); cin.get();
            }
        }
        else {
            cout << "Nie ma takiej opcji w menu!" << endl;
            cout << "\nNacisnij ENTER aby kontynuowac...";
            cin.ignore(); cin.get();
        }
    }
}

double wczytajLiczbe() {
    char bufor[50];
    bool liczbaPoprawna = false;
    double wynik = 0;

    while (!liczbaPoprawna) {
        cin >> bufor;
        char* endptr;
        wynik = strtod(bufor, &endptr);

        if (*endptr != '\0') {
            cout << "Brak dostepu do Mensy. Sprobuj wprowadzic prawidlowy zapis liczby: ";
        } else {
            liczbaPoprawna = true;
        }
    }
    return wynik;
}

float przeliczOgolem(float temp, char z, char na) {
    if (z == 'F' && na == 'C') return FtoC(temp);
    if (z == 'F' && na == 'K') return FtoK(temp);
    if (z == 'C' && na == 'F') return CtoF(temp);
    if (z == 'C' && na == 'K') return CtoK(temp);
    if (z == 'K' && na == 'F') return KtoF(temp);
    if (z == 'K' && na == 'C') return KtoC(temp);
    return temp;
}

void dodajDoHistorii(float wejscie, char skalaWej, float wyjscie, char skalaWyj) {
    if (dataCounter < MAX_SIZE - 1) {
        historiaWartosci[dataCounter] = wejscie;
        historiaJednostek[dataCounter] = skalaWej;

        historiaWartosci[dataCounter + 1] = wyjscie;
        historiaJednostek[dataCounter + 1] = skalaWyj;

        dataCounter += 2;
    } else {
        cout << "[WARNING] Nowe przeliczenie nie zostalo dodane do historii. Brak miejsca!" << endl;
    }
}

void pokazHistorie() {
    cout << "\n=== OPCJE WYSWIETLANIA HISTORII ===" << endl;
    cout << "1. Tylko C -> inne" << endl;
    cout << "2. Tylko F -> inne" << endl;
    cout << "3. Tylko K -> inne" << endl;
    cout << "4. Cala historia" << endl;
    cout << "Wybierz: ";
    int opcja = (int)wczytajLiczbe();

    char szukana = 0;
    if (opcja == 1) szukana = 'C';
    else if (opcja == 2) szukana = 'F';
    else if (opcja == 3) szukana = 'K';
    
    cout << "\n--- HISTORIA ---" << endl;
    bool znaleziono = false;
    int licznikLinii = 1;

    for (int i = 0; i < dataCounter / 2; i++) {
        int idx = i * 2;
        char zrodlowa = historiaJednostek[idx];

        if (opcja == 4 || zrodlowa == szukana) {
            cout << "<" << licznikLinii << "> "
                 << historiaWartosci[idx] << historiaJednostek[idx]
                 << " -> "
                 << historiaWartosci[idx + 1] << historiaJednostek[idx + 1]
                 << endl;
            znaleziono = true;
        }
        licznikLinii++;
    }

    if (!znaleziono) {
        cout << "brak danych." << endl;
    }
    
    cout << "\nNacisnij ENTER...";
    cin.ignore(); cin.get();
}

void usunZHistorii() {
    if (dataCounter == 0) {
        cout << "Historia jest pusta." << endl;
        cout << "\nNacisnij ENTER...";
        cin.ignore(); cin.get();
        return;
    }
    
    for (int i = 0; i < dataCounter / 2; i++) {
        cout << i + 1 << ". " 
             << historiaWartosci[i*2] << historiaJednostek[i*2] << " -> "
             << historiaWartosci[i*2+1] << historiaJednostek[i*2+1] << endl;
    }

    cout << "Podaj numer linii do usuniecia: ";
    int nr = (int)wczytajLiczbe();

    if (nr < 1 || nr > dataCounter / 2) {
        cout << "Nie ma takiego wpisu." << endl;
        cout << "\nNacisnij ENTER...";
        cin.ignore(); cin.get();
        return;
    }

    int entityToRemove = nr; 
    int startIdx = entityToRemove * 2; 

    for (int i = startIdx; i < dataCounter; i++) {
        historiaWartosci[i - 2] = historiaWartosci[i];
        historiaJednostek[i - 2] = historiaJednostek[i];
    }

    dataCounter -= 2;
    cout << "Wpis usuniety." << endl;
    cout << "\nNacisnij ENTER...";
    cin.ignore(); cin.get();
}

void modyfikujHistorie() {
    if (dataCounter == 0) {
        cout << "Historia jest pusta." << endl;
        cout << "\nNacisnij ENTER...";
        cin.ignore(); cin.get();
        return;
    }

    for (int i = 0; i < dataCounter / 2; i++) {
        cout << i + 1 << ". " 
             << historiaWartosci[i*2] << historiaJednostek[i*2] << " -> "
             << historiaWartosci[i*2+1] << historiaJednostek[i*2+1] << endl;
    }

    cout << "Ktory wpis zmodyfikowac? ";
    int nr = (int)wczytajLiczbe();

    if (nr < 1 || nr > dataCounter / 2) {
        cout << "Niepoprawny numer." << endl;
        cout << "\nNacisnij ENTER...";
        cin.ignore(); cin.get();
        return;
    }

    int idx = (nr - 1) * 2;

    cout << "Podaj nowa temperature: ";
    float nowaWartosc = (float)wczytajLiczbe();
    
    cout << "Podaj nowa skale zrodlowa (C/F/K): ";
    char nowaSkala;
    cin >> nowaSkala;
    if(nowaSkala >= 'a' && nowaSkala <= 'z') nowaSkala -= 32;

    cout << "Na co przeliczyc (C/F/K)? ";
    char celSkala;
    cin >> celSkala;
    if(celSkala >= 'a' && celSkala <= 'z') celSkala -= 32;

    if (check(nowaWartosc, nowaSkala) == -999.0f) {
        cout << "Blad: Temperatura ponizej zera absolutnego. Anulowano modyfikacje." << endl;
        cout << "\nNacisnij ENTER...";
        cin.ignore(); cin.get();
        return;
    }

    float nowyWynik = przeliczOgolem(nowaWartosc, nowaSkala, celSkala);

    historiaWartosci[idx] = nowaWartosc;
    historiaJednostek[idx] = nowaSkala;
    
    historiaWartosci[idx+1] = nowyWynik;
    historiaJednostek[idx+1] = celSkala;

    cout << "Zmodyfikowano wpis!" << endl;
    cout << "\nNacisnij ENTER...";
    cin.ignore(); cin.get();
}

void wypelnijLosowo() {
    cout << "Ile losowych wartosci przeliczyc? ";
    int ilosc = (int)wczytajLiczbe();

    if (dataCounter + (ilosc * 2) > MAX_SIZE) {
        int dostepneMiejsca = (MAX_SIZE - dataCounter) / 2;
        cout << "Brak miejsca na " << ilosc << " wpisow." << endl;
        cout << "Zostalo miejsca tylko na " << dostepneMiejsca << " wpisow." << endl;
        cout << "Czy wygenerowac tyle ile sie da? (1-Tak, 0-Nie): ";
        int dec = (int)wczytajLiczbe();
        if (dec != 1) return;
        ilosc = dostepneMiejsca;
    }

    for (int i = 0; i < ilosc; i++) {
        char skalaWej = 'C';
        int r = rand() % 3;
        if (r == 0) skalaWej = 'C';
        else if (r == 1) skalaWej = 'F';
        else skalaWej = 'K';

        int minTemp = 0;
        if (skalaWej == 'C') minTemp = -273;
        else if (skalaWej == 'F') minTemp = -459;
        
        int wylosowanaInt = minTemp + (rand() % 1001);
        double temp = (double)wylosowanaInt;

        char skalaWyj = 'C';
        int r2 = rand() % 3;
        if (r2 == 0) skalaWyj = 'C';
        else if (r2 == 1) skalaWyj = 'F';
        else skalaWyj = 'K';

        float wynik = przeliczOgolem(temp, skalaWej, skalaWyj);
        
        historiaWartosci[dataCounter] = temp;
        historiaJednostek[dataCounter] = skalaWej;
        historiaWartosci[dataCounter + 1] = wynik;
        historiaJednostek[dataCounter + 1] = skalaWyj;
        dataCounter += 2;
    }
    cout << "Wygenerowano i dodano wpisy." << endl;
    cout << "\nNacisnij ENTER...";
    cin.ignore(); cin.get();
}

float check(float temp, char stopnie) {
    if (stopnie == 'K' && temp < 0) return -999.0f;
    else if (stopnie == 'C' && temp < -273.15f) return -999.0f;
    else if (stopnie == 'F' && temp < -459.67f) return -999.0f;
    return temp;
}

float CtoF(float stopnie) { return stopnie * (9.0f / 5.0f) + 32.0f; }
float CtoK(float stopnie) { return stopnie + 273.15f; }
float FtoC(float stopnie) { return (5.0f / 9.0f) * (stopnie - 32.0f); }
float FtoK(float stopnie) { return (stopnie + 459.67f) * (5.0f / 9.0f); }
float KtoC(float stopnie) { return stopnie - 273.15f; }
float KtoF(float stopnie) { return stopnie * (9.0f / 5.0f) - 459.67f; }
