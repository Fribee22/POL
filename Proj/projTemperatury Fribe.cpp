#include "headerFile.h"

float pobierzF() {
    float temp;
    cout << "Podaj temperature w Fahrenheitach: ";
    cin >> temp;
    return temp;
}
float pobierzC() {
    float temp;
    cout << "Podaj temperature w Celsiusach: ";
    cin >> temp;
    return temp;
}
float pobierzK() {
    float temp;
    cout << "Podaj temperature w Kelwinach: ";
    cin >> temp;
    return temp;
}


int main()
{
    int wybor;

    while (true)
    {
        system("cls");
        menu();
        cout << "wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
        {
            float f = pobierzF();
            if (check(f, 'F') == -999) {
                cout << "nie ma takiej temperatury" << endl;
            }
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
            if (check(f, 'F') == -999) {
                cout << "nie ma takiej temperatury" << endl;
            }

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
            if (check(c, 'C') == -999) {
                cout << "nie ma takiej temperatury" << endl;
            }

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
            if (check(c, 'C') == -999) {
                cout << "nie ma takiej temperatury" << endl;
            }
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
            if (check(k, 'K') == -999) {
                cout << "nie ma takiej temperatury" << endl;
            }
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
            if (check(k, 'K') == -999) {
                cout << "nie ma takiej temperatury" << endl;
            }
            else {
                float f = KtoF(k);
                zapisz(k, 'K', f, 'F');
                cout << k << " K to " << f << " F" << endl;

            }
        }
        break;

        case 7:

            cout << "koniec programu";
            return 0;

        case 8:
            pokazHistorie();
            break;

        default:

            return 0;
        }
        cout << "wcisnij ENTER, aby kontynouwac";
        cin.ignore();
        cin.get();
    }

    return 0;
}
void pokazHistorie() {
    cout << "Historia Przeliczen" << endl;
    for (int i = 0; i < dataCounter; i += 2) {
        int numerWpisu = (i / 2) + 1;

        cout << " < " << numerWpisu << "> ";
        cout << historiaTemp[i] << historiaJedn[i];
        cout << " = ";
        cout << historiaTemp[i + 1] << historiaJedn[i + 1];
        cout << endl;
    }
}
void zapisz(float stara, char staraJ, float nowa, char nowaJ) {
    if (dataCounter < 98) {
        historiaTemp[dataCounter] = stara;
        historiaJedn[dataCounter] = staraJ;
        dataCounter++;


        historiaTemp[dataCounter] = nowa;
        historiaJedn[dataCounter] = nowaJ;
        dataCounter++;

    }
    else {
        cout << "brak miejsca w pamieci historii" << endl;
    }
}

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
    cout << "7: Koniec programu" << endl;
    cout << "8: Pokaz historie" << endl;
}

float FtoC(float F) {
    return (F - 32.0) * 5.0 / 9.0;
}
float FtoK(float F) {
    return (F + 459.67) * 5.0 / 9.0;
}
float CtoF(float C) {
    return C * 9.0 / 5.0 + 32.0;
}
float CtoK(float C) {
    return C + 273.15;
}
float KtoC(float K) {
    return K - 273.15;
}
float KtoF(float K) {
    return K * 9.0 / 5.0 - 459.67;
}
