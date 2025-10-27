//////////////zad1
#include <iostream>
using namespace std;
int main() {
    for (int i = 10; i >= 0; i--) {
        cout << i << endl;
    }
    return 0;
}

////////////////////////////zad2



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
/////////////////////////////zad3
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int fahr, celsius;
    int start, limit, krok;

    start = 0;
    limit = 200;
    krok = 20;

    for (fahr = 0.0; fahr <= limit; fahr = fahr + krok)
    {
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        cout << fahr << "\t" << celsius << endl;
    }




}
//////////////////zad5, liczba MUSI byæ z przecinek 

#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int fahr, celsius;
    int start, limit, krok;

    start = 0;
    limit = 200;
    krok = 20;

    for (fahr = 0.0; fahr <= limit; fahr = fahr + krok)
    {
        float celsius = (5 / 9) * (fahr - 32.0);
        cout << fahr << "\t" << celsius << endl;
    }




}
/////////////////zad6

#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int fahr, celsius;
    int start, limit, krok;

    start = 0;
    cin >> limit;
    cin >> krok;

    for (fahr = 0.0; fahr <= limit; fahr = fahr + krok)
    {
        int yest = 0;
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        cout << fahr << "\t" << celsius << endl;
    }




}
////////////zad7
