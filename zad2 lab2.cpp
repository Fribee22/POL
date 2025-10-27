#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int fahr, celsius;
    int start, limit, krok;

    start = 0;
    limit = 200;
    krok = 20;

    fahr = start;

    while (fahr <= limit) {
        celsius = 5 * (fahr - 32) / 9;
        cout << fahr << "\t" << celsius << endl;
        fahr = fahr + krok;

    }


}
