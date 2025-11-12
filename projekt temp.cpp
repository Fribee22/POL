#include <iostream>
#include <stdio.h>

using namespace std;

float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);

float CtoF(float stopnie) {
	float C = stopnie;
	float wynik = C * (9.0 / 5.0) + 32.0;
	return wynik;
}
float CtoK(float stopnie) {
	float C = stopnie;
	float wynik = C + 273.15;
	return wynik;
}
float FtoC(float stopnie) {
	float F = stopnie;
	float wynik = (5.0 / 9.0) * (F - 32.0);
	return wynik;
}
float FtoK(float stopnie) {
	float F = stopnie;
	float wynik = (F + 459.67) * (5.0 / 9.0);
	return wynik;
}
float KtoC(float stopnie) {
	float K = stopnie;
	float wynik = K - 273.15;
	return wynik;
}
float KtoF(float stopnie) {
	float K = stopnie;
	float wynik = K * (9.0 / 5.0) - 459.67;
	return wynik;
}






int main() {
	float stopnie;


	int wybor;
	cout << "1. przelicz Fahr na Celsius \n";
	cout << "2. przelicz Fahr na Kelwin \n";
	cout << "3. przelicz Celsius na Fahr \n";
	cout << "4. przelicz Celsius na Kelwin\n";
	cout << "5. przelicz Kelwin na Fahr \n";
	cout << "6. przelicz kelwin na Celsius \n";
	cout << "7. koniec programu \n";

	cout << "wybierz numer: ";
	cin >> wybor;
	if (wybor > 7) {
		cout << "cos poszlo nie tak" << endl;


	}
	else if (wybor == 7) {
		cout << "koniec programu" << endl;


	}
	else {
		cout << "podaj temperature do przeliczenia: ";
		cin >> stopnie;
	}

	switch (wybor) {
	case 1:
		cout << "przelicz " << stopnie << " Fahr -> Celsius " << FtoC(stopnie) << endl;
		break;
	case 2:
		cout << "przelicz " << stopnie << " Fahr -> Kelwin " << FtoK(stopnie) << endl;
		break;
	case 3:
		cout << "przelicz " << stopnie << " Celsius -> Fahr " << CtoF(stopnie) << endl;
		break;
	case 4:
		cout << "przelicz " << stopnie << " Celsius -> Kelwin " << CtoK(stopnie) << endl;
		break;
	case 5:
		cout << "przelicz " << stopnie << " Kelwin->Celsius " << KtoC(stopnie) << endl;
		break;
	case 6:
		cout << "przelicz " << stopnie << " Kelwin->Fahr" << KtoF(stopnie) << endl;
		break;
	default:
		cout << "Nieznana opcja." << endl;
	}



















}



