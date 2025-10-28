

#include <iostream>
#include <stdio.h>
using namespace std;
void fir(int a, int b);
int sec(int a, int b);

int main() {
	int a;
	int b;

	cout << "podaj pierwsza liczbe: " << endl;
	cin >> a;
	cout << "podaj druga liczbe: " << endl;
	cin >> b;

	fir(a, b);
	sec(a, b);
}




void fir(int a, int b) {
	if (a > b) {
		cout << a << "jest wieksze od" << b << endl;

	}
	else if (b > a) {
		cout << b << " jest wieksze od " << a << endl;

	}
	else {
		cout << "liczby są równe" << endl;
	}


}
int sec(int a, int b) {
	if (a > b) {
		cout << a << endl;
	}
	else {
		cout << b;
	}

}














