//Napisz program, który obliczy sumę cyfr liczby naturalnej podanej przez użytkownika. Zaimplementuj
// dwie wersje funkcji: iteracyjną i rekurencyjną

#include <iostream>
#include <stdio.h>

using namespace std;

int sumaCit(int n){
    int suma = 0;
    while (n > 0){
        suma += n % 10;
        n /=10;
    }
    return suma;
}
int sumaCre(int n){
    if (n == 0 ) return 0;
    return (n % 10) + sumaCre(n / 10);
}

int main(){
    int liczba;
    cout << "Podaj liczbe naturalna";
    cin >> liczba;
    
    cout << sumaCit(liczba) << endl;
    cout << sumaCre(liczba) << endl;
    
    return 0;
}