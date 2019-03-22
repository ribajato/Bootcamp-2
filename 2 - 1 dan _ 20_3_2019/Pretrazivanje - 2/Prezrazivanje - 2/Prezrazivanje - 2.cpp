// Prezrazivanje - 2
//Napravite program koji rjesava igru pogađanja brojeva (manje ili više)


#include "pch.h"
#include <iostream>
#include <cstdlib> // za srand
#include <ctime>  //
//#include <vector>

using namespace std;

int main()
{
	srand(time(NULL));
	int broj;  
	broj = rand() % 100 + 1;
	int sredina;
	int pocetak = 1;
	int kraj = 100;
	int brojac = 0;
	sredina = (pocetak + kraj)/2;
	cout << "Na pocetku \n";
	cout <<"sredina je: " << sredina;
	cout << "\nzamisljeni broj je: " << broj << endl;
	system("pause");
	do{
		brojac += 1;
		cout << "Pokusali smo s " << sredina << endl;
		if (broj < sredina)
		{
			cout << "Trazeni broj je manji od " << sredina << endl;
			kraj = sredina;
		}
		else if (broj > sredina)
		{
			cout << "Trazeni broj je veci od " << sredina << endl;
			pocetak = sredina;
		}
		sredina = (pocetak + kraj) / 2;
	} while (sredina != broj && pocetak < kraj);
	if (sredina == broj) {
		cout << "Racunalo je pronaslo trazeni broj!" << endl;
	}
	cout << "Zamisljeni broj smo pronasli u " << brojac + 1 << " krugova." << endl;
}