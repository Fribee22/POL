#include <iostream>
#include <stdio.h>

using namespace std;

int silnia(int n, int i = 1);

int main(){
    cout << "podaj wielkosc" << endl;
    int n;
    cin >> n;
    silnia(n);
    
    return 0;
}
 
 int silnia ( int n, int i ) {
    if ( i > n){
    cout << "*" << endl;
    return 1;
    }
    else{
        for(int k = 0; k < n - i; k++) cout << " ";
        for(int k = 0; k < (2 * i) - 1; k++) cout << "*";
        
        cout << endl;
    return i * silnia (n, i + 1); 
    }
 }
