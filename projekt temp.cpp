#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;



double historiaWartosci[100] = { 0.0 };


char historiaJednostek[100] = { 0 };



int dataCounter = 0;



float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);

float check(float temp, char stopnie);


int main() {
    float stopnie;
    int wybor;

    while (true) {
        system("cls"); 

        cout << "=== MENU KONWERSJI TEMPERATUR ===" << endl;
        cout << "1. przelicz Fahr na Celsius \n";
        cout << "2. przelicz Fahr na Kelwin \n";
        cout << "3. przelicz Celsius na Fahr \n";
        cout << "4. przelicz Celsius na Kelwin\n";
        cout << "5. przelicz Kelwin na Fahr \n";
        cout << "6. przelicz kelwin na Celsius \n";
        cout << "7. KONIEC PROGRAMU \n";
        cout << "8. Pokaz historie \n"; 
        cout << "=================================" << endl;

        cout << "wybierz numer: ";
        cin >> wybor;

        
        if (wybor == 7) {
            return 0;
        }

        
        if (wybor == 8) {
            cout << "\n=== HISTORIA PRZELICZEN ===" << endl;
            if (dataCounter == 0) {
                cout << "(Brak historii)" << endl;
            }
            else {
               
                for (int i = 0; i < dataCounter / 2; i++) {
                    
                    int index = i * 2;
                    
                    cout << "<" << i + 1 << "> "
                         << historiaWartosci[index] << historiaJednostek[index] 
                         << " = "
                         << historiaWartosci[index + 1] << historiaJednostek[index + 1] 
                         << endl;
                }
            }
        }
       
        else if (wybor < 1 || wybor > 8) {
            cout << "Nie ma takiej opcji w menu!" << endl;
        }
        
        else {
            cout << "podaj temperature do przeliczenia: ";
            cin >> stopnie;

            char skalaWejsciowa, skalaWynikowa;

           
            if (wybor == 1 || wybor == 2) skalaWejsciowa = 'F';
            else if (wybor == 3 || wybor == 4) skalaWejsciowa = 'C';
            else skalaWejsciowa = 'K';

           
            float wynikCheck = check(stopnie, skalaWejsciowa);

            if (wynikCheck == -999.0f) {
                cout << "\nBLAD: Nie ma takiej temperatury (ponizej zera absolutnego)!" << endl;
            }
            else {
                float wynik = 0;

                switch (wybor) {
                case 1: wynik = FtoC(stopnie); skalaWynikowa = 'C'; break;
                case 2: wynik = FtoK(stopnie); skalaWynikowa = 'K'; break;
                case 3: wynik = CtoF(stopnie); skalaWynikowa = 'F'; break;
                case 4: wynik = CtoK(stopnie); skalaWynikowa = 'K'; break;
                case 5: wynik = KtoF(stopnie); skalaWynikowa = 'F'; break;
                case 6: wynik = KtoC(stopnie); skalaWynikowa = 'C'; break;
                }

                
                cout << "\nWynik: " << stopnie << " " << skalaWejsciowa
                     << " = " << wynik << " " << skalaWynikowa << endl;

               
                if (dataCounter < 98) {
                    
                    historiaWartosci[dataCounter] = stopnie;
                    historiaJednostek[dataCounter] = skalaWejsciowa;

                    
                    historiaWartosci[dataCounter + 1] = wynik;
                    historiaJednostek[dataCounter + 1] = skalaWynikowa;

                    
                    dataCounter += 2;
                }
                else {
                    cout << "[Ostrzezenie] Brak miejsca w historii!" << endl;
                }
            }
        }

        
        cout << "\nNacisnij ENTER, aby wrocic do menu...";
        cin.ignore();
        cin.get();
    }
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
