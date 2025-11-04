

#include <iostream>
#include <stdio.h>

using namespace std;
/*
int main() {
	int tab[10];

	for (int i = 0; i < 10; i++) {
		cout << "wprowadz liczbe" << endl;
		cin >> tab[i];

	}

	for (int i = 9; i >= 0; i--) {
		cout << tab[i] << endl;
	}


	

}
*/

int main() {

	int liczby;
	

	
	cout << "ile liczb chcesz?" << endl;

	cin >> liczby;
	int* tab = new int[liczby];

	tab[0] =  0;
	tab[1] =  1;

	for (int i = 2; i <= liczby; i++) {
		tab[i] = tab[i - 1] + tab[i - 2];
		cout << liczby << endl;


	}







	





	
	
}

