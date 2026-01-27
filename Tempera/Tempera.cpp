#include "headerFile.h"

int main()
{
    
    srand(time(NULL));

    int wybor;

    while (true)
    {
        system("cls");
        menu();
        cout << "Wybierz opcje: ";

        
        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(1000, '\n');
            wybor = 0; 
        }

        
        if (wybor == -1)
        {
            cout << "Koniec programu." << endl;
            return 0;
        }

        switch (wybor)
        {
        case 1:
        {
            float f = pobierzF();
            if (check(f, 'F') == -999) cout << "NIEMOZLIWE" << endl;
            else {
                float c = FtoC(f);
                zapisz(f, 'F', c, 'C');
                cout << f << " F to " << c << " C" << endl;
            }
        }
        break;

        case 2:
        {
            float f = pobierzF();
            if (check(f, 'F') == -999) cout << "NIEMOŻLIWE" << endl;
            else {
                float k = FtoK(f);
                zapisz(f, 'F', k, 'K');
                cout << f << " F to " << k << " K" << endl;
            }
        }
        break;

        case 3:
        {
            float c = pobierzC();
            if (check(c, 'C') == -999) cout << "NIEMOŻLIWE" << endl;
            else {
                float f = CtoF(c);
                zapisz(c, 'C', f, 'F');
                cout << c << " C to " << f << " F" << endl;
            }
        }
        break;

        case 4:
        {
            float c = pobierzC();
            if (check(c, 'C') == -999) cout << "NIEMOZLIWE" << endl;
            else {
                float k = CtoK(c);
                zapisz(c, 'C', k, 'K');
                cout << c << " C to " << k << " K" << endl;
            }
        }
        break;

        case 5:
        {
            float k = pobierzK();
            if (check(k, 'K') == -999) cout << "NIEMOZLIWEE" << endl;
            else {
                float c = KtoC(k);
                zapisz(k, 'K', c, 'C');
                cout << k << " K to " << c << " C" << endl;
            }
        }
        break;

        case 6:
        {
            float k = pobierzK();
            if (check(k, 'K') == -999) cout << "NIEMOZLIWE" << endl;
            else {
                float f = KtoF(k);
                zapisz(k, 'K', f, 'F');
                cout << k << " K to " << f << " F" << endl;
            }
        }
        break;

      
        case 8:
            pokazHistorie();
            break;

        case 9:
            usunWpis();
            break;

        case 10:
            modyfikujWpis();
            break;

        case 11:
            generujLosowe();
            break;

        default:
            cout << "Nie ma takiej opcji!" << endl;
            break;
        }
        cout << "\nWcisnij ENTER, aby kontynuowac...";
        cin.ignore();
        cin.get();
    }

    return 0;
}




float pobierzLiczbe() {
    string wejscie;
    while (true) {
        cin >> wejscie;

        bool czyToLiczba = true;
        int licznikKropek = 0;
        int licznikMinusow = 0;

        for (int i = 0; i < wejscie.length(); i++) {
            if (wejscie[i] == '.') {
                licznikKropek++;
                if (licznikKropek > 1) czyToLiczba = false;
            }
            else if (wejscie[i] == '-') {
                licznikMinusow++;
                if (licznikMinusow > 1 || i > 0) czyToLiczba = false;
            }
            else if (wejscie[i] < '0' || wejscie[i] > '9') {
                czyToLiczba = false;
            }
        }

        if (czyToLiczba && wejscie != "." && wejscie != "-") {
            return stof(wejscie); 
        }
        else {
            cout << "To nie jest poprawna liczba!!!!!!!!!!!!!!! Sprobuj ponownie prosze: ";
        }
    }
}


void zapisz(float stara, char staraJ, float nowa, char nowaJ) {
    if (dataCounter + 1 < ROZMIAR_TABLICY) {
        historiaTemp[dataCounter] = stara;
        historiaJedn[dataCounter] = staraJ;
        dataCounter++;

        historiaTemp[dataCounter] = nowa;
        historiaJedn[dataCounter] = nowaJ;
        dataCounter++;
    }
    else {
        cout << "\n[OSTRZEZENIE] Brak miejsca w historii!!!!!!!!!! Wyswietle Ci ale nie zapisze." << endl;
    }
}


void pokazHistorie() {
    system("cls");
    cout << "FILTR HISTORII" << endl;
    cout << "1. Tylko C -> inne" << endl;
    cout << "2. Tylko F -> inne" << endl;
    cout << "3. Tylko K -> inne" << endl;
    cout << "4. Pokaz cala historie" << endl;
    cout << "Wybierz opcje filtra: ";

    int opcja;
    cin >> opcja;

    char szukanaJednostka = 'X';
    if (opcja == 1) szukanaJednostka = 'C';
    else if (opcja == 2) szukanaJednostka = 'F';
    else if (opcja == 3) szukanaJednostka = 'K';
    else if (opcja == 4) szukanaJednostka = 'A'; 
    else {
        cout << "Niepoprawna opcja!!!! Wracam do menu." << endl;
        return;
    }

    cout << "\n--- WYNIKI ---" << endl;
    bool znalezionoCokolwiek = false;

    for (int i = 0; i < dataCounter; i += 2) {
        if (szukanaJednostka == 'A' || historiaJedn[i] == szukanaJednostka) {
            int numerWpisu = (i / 2) + 1;
            cout << "<" << numerWpisu << "> ";
            cout << historiaTemp[i] << historiaJedn[i] << " = " << historiaTemp[i + 1] << historiaJedn[i + 1];
            cout << endl;
            znalezionoCokolwiek = true;
        }
    }

    if (!znalezionoCokolwiek) cout << "Brak danych ktore spelniaja kryteria." << endl;
}


void usunWpis() {
    system("cls");
    cout << "USUWANIE WPISU" << endl;

    if (dataCounter == 0) {
        cout << "Historia jest pusta." << endl;
        return;
    }

    
    for (int i = 0; i < dataCounter; i += 2) {
        int numer = (i / 2) + 1;
        cout << "<" << numer << "> " << historiaTemp[i] << historiaJedn[i] << "..." << endl;
    }

    cout << "Podaj numer wpisu do usuniecia: ";
    int nr;
    cin >> nr;

    int maksNumer = dataCounter / 2;
    if (nr < 1 || nr > maksNumer) {
        cout << "Nie ma takiego wpisu!" << endl;
        return;
    }

    
    int startIdx = (nr - 1) * 2;
    for (int i = startIdx; i < dataCounter - 2; i++) {
        historiaTemp[i] = historiaTemp[i + 2];
        historiaJedn[i] = historiaJedn[i + 2];
    }

    dataCounter -= 2;
    cout << "Wpis usuniety pomyslnie." << endl;
}


void modyfikujWpis() {
    system("cls");
    cout << "MODYFIKACJA WPISU" << endl;
    if (dataCounter == 0) { cout << "Brak historii." << endl; return; }

    
    for (int i = 0; i < dataCounter; i += 2) {
        cout << "<" << (i / 2) + 1 << "> " << historiaTemp[i] << historiaJedn[i] << " -> " << historiaTemp[i + 1] << historiaJedn[i + 1] << endl;
    }

    cout << "Ktory wpis zmodyfikowac? ";
    int nr; cin >> nr;

    if (nr < 1 || nr > dataCounter / 2) { cout << "Bledny numer." << endl; return; }

    
    cout << "Podaj nowa temperature: ";
    float nowaT = pobierzLiczbe();
    cout << "Podaj nowa skale wejsciowa (C, F, K): ";
    char skalaWe; cin >> skalaWe; skalaWe = toupper(skalaWe);
    cout << "Podaj nowa skale docelowa (C, F, K): ";
    char skalaWy; cin >> skalaWy; skalaWy = toupper(skalaWy);

    if (check(nowaT, skalaWe) == -999) {
        cout << "Blad: Temperatura ponizej zera absolutnego!" << endl;
        return;
    }

    
    float wynik = 0;
    bool git = true;
    if (skalaWe == 'C' && skalaWy == 'F') wynik = CtoF(nowaT);
    else if (skalaWe == 'C' && skalaWy == 'K') wynik = CtoK(nowaT);
    else if (skalaWe == 'F' && skalaWy == 'C') wynik = FtoC(nowaT);
    else if (skalaWe == 'F' && skalaWy == 'K') wynik = FtoK(nowaT);
    else if (skalaWe == 'K' && skalaWy == 'C') wynik = KtoC(nowaT);
    else if (skalaWe == 'K' && skalaWy == 'F') wynik = KtoF(nowaT);
    else { cout << "Nieznana kombinacja skal." << endl; git = false; }

    
    if (git) {
        int idx = (nr - 1) * 2;
        historiaTemp[idx] = nowaT;
        historiaJedn[idx] = skalaWe;
        historiaTemp[idx + 1] = wynik;
        historiaJedn[idx + 1] = skalaWy;
        cout << "Zaktualizowano!" << endl;
    }
}


void generujLosowe() {
    system("cls");
    cout << "GENERATOR LOSOWY " << endl;
    cout << "Ile wpisow wygenerowac? ";

    int liczbaProb;
    cin >> liczbaProb;

    
    int dostepneSloty = (ROZMIAR_TABLICY - dataCounter) / 2;

    if (liczbaProb > dostepneSloty) {
        cout << "Brak miejsca na " << liczbaProb << ". Dostepne: " << dostepneSloty << "." << endl;
        cout << "Czy wypelnic tyle ile sie da? (1-TAK, 0-NIE): ";
        int decyzja;
        cin >> decyzja;
        if (decyzja != 1) return;
        liczbaProb = dostepneSloty;
    }

    cout << "\nWYLOSOWANE WARTOSCI" << endl;

    for (int i = 0; i < liczbaProb; i++) {
        char jednostkaZrodlowa, jednostkaDocelowa;
        float wartoscZrodlowa, wartoscWynikowa;

        
        int wylosowanyTyp = rand() % 3;

        switch (wylosowanyTyp) {
        case 0: 
            jednostkaZrodlowa = 'C';
            
            wartoscZrodlowa = (float)((rand() % 1001) - 273);
            break;

        case 1: 
            jednostkaZrodlowa = 'F';
            
            wartoscZrodlowa = (float)((rand() % 1001) - 459);
            break;

        case 2: 
            jednostkaZrodlowa = 'K';
           
            wartoscZrodlowa = (float)(rand() % 1001);
            break;
        }

        
        int rzutMoneta = rand() % 2;

        if (jednostkaZrodlowa == 'C') {
            if (rzutMoneta == 0) { jednostkaDocelowa = 'F'; wartoscWynikowa = CtoF(wartoscZrodlowa); }
            else { jednostkaDocelowa = 'K'; wartoscWynikowa = CtoK(wartoscZrodlowa); }
        }
        else if (jednostkaZrodlowa == 'F') {
            if (rzutMoneta == 0) { jednostkaDocelowa = 'C'; wartoscWynikowa = FtoC(wartoscZrodlowa); }
            else { jednostkaDocelowa = 'K'; wartoscWynikowa = FtoK(wartoscZrodlowa); }
        }
        else { 
            if (rzutMoneta == 0) { jednostkaDocelowa = 'C'; wartoscWynikowa = KtoC(wartoscZrodlowa); }
            else { jednostkaDocelowa = 'F'; wartoscWynikowa = KtoF(wartoscZrodlowa); }
        }

      
        historiaTemp[dataCounter] = wartoscZrodlowa;
        historiaJedn[dataCounter] = jednostkaZrodlowa;
        dataCounter++;

        historiaTemp[dataCounter] = wartoscWynikowa;
        historiaJedn[dataCounter] = jednostkaDocelowa;
        dataCounter++;

        
        cout << i + 1 << ". Wylosowano: " << wartoscZrodlowa << jednostkaZrodlowa
            << " -> Przeliczono na: " << wartoscWynikowa << jednostkaDocelowa << endl;
    }

    cout << "\nZakonczono losowanie. Dane zapisane w historii." << endl;
}



float pobierzF() { cout << "Podaj temp w Fahrenheitach: "; return pobierzLiczbe(); }
float pobierzC() { cout << "Podaj temp w Celsiusach: "; return pobierzLiczbe(); }
float pobierzK() { cout << "Podaj temp w Kelwinach: "; return pobierzLiczbe(); }

int check(float temp, char stopnie) {
    if (stopnie == 'K' && temp < 0) return -999;
    if (stopnie == 'C' && temp < -273.15) return -999;
    if (stopnie == 'F' && temp < -459.67) return -999;
    return 0;
}

void menu() {
    cout << "1: Przelicz Fahr -> Celsius" << endl;
    cout << "2: Przelicz Fahr-> Kelwin" << endl;
    cout << "3: Przelicz Celsius-> Fahr" << endl;
    cout << "4: Przelicz Celsius-> Kelwin" << endl;
    cout << "5: Przelicz Kelwin-> Celsius" << endl;
    cout << "6: Przelicz Kelwin-> Fahr" << endl;
    cout << "---------------------------" << endl;
    cout << "8: Pokaz historie (filtrowanie)" << endl;
    cout << "9: Usun wpis z historii" << endl;
    cout << "10: Modyfikuj wpis" << endl;
    cout << "11: Generuj losowe dane" << endl;
    cout << "-1: Koniec programu" << endl;
}

float FtoC(float F) { return (F - 32.0) * 5.0 / 9.0; }
float FtoK(float F) { return (F + 459.67) * 5.0 / 9.0; }
float CtoF(float C) { return C * 9.0 / 5.0 + 32.0; }
float CtoK(float C) { return C + 273.15; }
float KtoC(float K) { return K - 273.15; }
float KtoF(float K) { return K * 9.0 / 5.0 - 459.67; }