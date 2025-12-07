#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;


float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);


float check(float temp, char stopnie) {
    if (stopnie == 'K' && temp < 0) return -999.0;
    else if (stopnie == 'C' && temp < -273.15) return -999.0;
    else if (stopnie == 'F' && temp < -459.67) return -999.0;
    return temp;
}


float CtoF(float stopnie) { return stopnie * (9.0 / 5.0) + 32.0; }
float CtoK(float stopnie) { return stopnie + 273.15; }
float FtoC(float stopnie) { return (5.0 / 9.0) * (stopnie - 32.0); }
float FtoK(float stopnie) { return (stopnie + 459.67) * (5.0 / 9.0); }
float KtoC(float stopnie) { return stopnie - 273.15; }
float KtoF(float stopnie) { return stopnie * (9.0 / 5.0) - 459.67; }

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
        cout << "=================================" << endl;

        cout << "wybierz numer: ";
        cin >> wybor;

       
        if (wybor == 7) {
            return 0; 
        }

        
        if (wybor < 1 || wybor > 7) {
            cout << "Nie ma takiej opcji w menu!" << endl;
        } 
        else {
            
            cout << "podaj temperature do przeliczenia: ";
            cin >> stopnie;

            
            char skalaWejsciowa;
            if (wybor == 1 || wybor == 2) skalaWejsciowa = 'F';
            else if (wybor == 3 || wybor == 4) skalaWejsciowa = 'C';
            else skalaWejsciowa = 'K';

            
            float wynikCheck = check(stopnie, skalaWejsciowa);

            if (wynikCheck == -999.0f) {
                
                cout << "\nBLAD: Nie ma takiej temperatury!" << endl;
                
            } else {
                
                cout << "\nWynik: ";
                switch (wybor) {
                    case 1: cout << stopnie << " F = " << FtoC(stopnie) << " C"; break;
                    case 2: cout << stopnie << " F = " << FtoK(stopnie) << " K"; break;
                    case 3: cout << stopnie << " C = " << CtoF(stopnie) << " F"; break;
                    case 4: cout << stopnie << " C = " << CtoK(stopnie) << " K"; break;
                    case 5: cout << stopnie << " K = " << KtoF(stopnie) << " F"; break;
                    case 6: cout << stopnie << " K = " << KtoC(stopnie) << " C"; break;
                }
                cout << endl;
            }
        }

        
        cout << "\nNacisnij ENTER, aby wrocic do menu...";
        cin.ignore(); 
        cin.get();    
    }
}

