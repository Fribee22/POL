///////////////zad1
#include <iostream>
#include <stdio.h>

using namespace std;

int main (){
    
    int a, b;
    
    cin >> a;
    cin >> b;
    
    if (a == b){
        cout << "liczby są sobie równe" << endl;
    }
    else if (a > b){
        cout << "liczba a jest wieksza od b" << endl;
    }
    else{
        cout << "liczba b jest wieksza od a" << endl;
    }
    
    
        
            
        
    
    
}

//////////zad2

#include <iostream>
#include <stdio.h>

using namespace std;

int main (){
    
    int a, b;
    
    cin >> a;
    cin >> b;
    
    if (a == b){
        cout << "liczby są sobie równe " << endl;
    }
    else{
        if (a > b){
            cout << "liczba a jest wieksza od b" << endl;
            }else {
                cout << "liczba b jest wieksza od a" << endl;
            }
        
    }
      
    
    
        
            
        
    
    
}
//////////////////////zad3
#include <iostream>
#include <stdio.h>

using namespace std;

int main (){
    
    float r;
    
    cin >> r;
    
    if (0.7 <= r <= 1){
        cout << "bardzo silna korelacja" << endl;
    }
    else if(r>=0.5){
        cout << "silna korelacja dodatnia" << endl;
        
    }
    else if(r>=0.3){
        cout << "umiarkowana korelacja" << endl;
    }
    else if(r>=0.2){
        cout << "słaba korelacja dodatnia" << endl;
    }
    else if(r>=0){
        cout << "brak  korelacja" << endl;
    }
    else{
        cout << "wtf" << endl;
    }
    
    
        
            
        
    
    
}
///////////////zad4
#include <iostream>
#include <stdio.h>

using namespace std;

int main (){
    
    int opcja;
    int a, b;
    
    cout << "wpisz z klawiatury 1 - dodawanie, 2 - odejmwoanie, 3 - mnożenie, 4 - dzielnie: ";
    cin >> opcja;
    
    cout << "Podaj liczbe a: ";
    cin >> a;
    cout << "Podaj liczbe b: ";
    cin >> b;
    
    switch (opcja){
        case 1:
        cout << "Suma: " << a + b << endl;
        break;
        case 2:
        cout << "Różnica: " << a - b << endl;
        break;
        case 3:
        cout << "iloczyn: " << a * b << endl;
        break;
        case 4:
        if (b == 0){
            cout << "nie dziel przez zero" << endl;
        }
        else{
            cout << "iloraz: " << a / b << endl;
        
        
        }
        break;
        
        
        
        
        
        
        
    }
///////////zad 5
#include <iostream>
using namespace std;
int main() {
    for (int i = 0; ; i + 2){
        cout << i;
    }
    return 0;
}

///////////zad6
#include <iostream>
#include <stdio.h>


using namespace std;


int main(){
    float a;
    float b;
    int decyzja;
    cin >> a;
    cin >> b;
    
    float suma = a + b;
    float odejmowanie = a - b;
    float mnozenie = a * b;
    float dzielenie = a/b;
    
    while(true){
    if (a == 0|| b == 0){
        cout << "suma: " << suma << endl;
        cout << "odejmowanie: " << odejmowanie << endl;
        cout << "mnozenie: " << mnozenie << endl;
        cout << "dzielenie: nie można dzielić przez 0 " << endl;
    }
    else {
        cout << "suma: " << suma << endl;
        cout << "odejmowanie: " << odejmowanie << endl;
        cout << "mnozenie: " << mnozenie << endl;
        cout << "dzielenie: " << dzielenie << endl;
        
        
    }
    
    cout << "czy zakonczyc 1-tak|2-nie" << endl;
    cin >> decyzja;
    
    if (decyzja == 1){
        cout << "program zakonczony" << endl;
        
        return 0;
    }
    
    
    
    

    
}
}





