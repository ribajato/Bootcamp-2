// Pretrazivanje-1
//Napravi program koji će pretražiti zadani pojam u listi pojmova. Pojmove zapišite (kopirajte) u jednu .txt datoteku (100 pojmova)
//te ih  učitajte iz te datoteke. Napravite dvije funkcije - jednu koja traži prvi put kada se pojavljuje element (indes),
//a drugu ukoliko se pojam nalazi na nekoliko mjesta ispišite sve indekse na kojima se nalazi.

// zadatak je rijesen na nacin da se koriste brojevi a ne pojmovi i ne ispisuje je i učitava podatke iz datoteke

#include "pch.h"
#include <iostream>
#include <cstdlib> // za srand
#include <ctime>  // 

using namespace std;

int linearno_pretrazivanje1(int polje[], int velicina, int trazenibroj) // broj se pojavljuje prvi puta
{
	for (int i = 0; i < 100; i++)
	{
		if (polje[i] == trazenibroj)
		{
			//cout << "Trazeni broj se nalazi na mjestu '"<<i<<"' u polju. To polje ima vrijednost: " << polje[i];
			return i;
		}
		
	}
	return -1;
}

void linearno_pretrazivanje2(int polje[], int velicina, int trazenibroj) // broj se pojavljuje vise puta
{
	cout << "Ako se broj pojavljuje vise puta\n";
	for (int i = 0; i < 100; i++)
	{
		if (polje[i] == trazenibroj)
		{
			cout << "Trazeni broj se nalazi na mjestu '" << i << "' u polju. To polje ima vrijednost: " << polje[i] << endl;
		}
		
	}

}

int main()
{
	int polje_brojeva[100];
	srand(time(NULL));
	
	for (int i = 0; i < 100; i++)
	{
		polje_brojeva[i]=rand() % 100 + 1;
	}
	cout << "Generirani brojevi u polju polje_brojeva su:\n";
	for (int i = 0; i < 100; i++)
	{
		cout << polje_brojeva[i] << " ";
	}

	int trazenibroj,nadiMiBroj;
	cout << "\nupisite koji broj pretrazujete: ";
	cin >> trazenibroj;
	nadiMiBroj=linearno_pretrazivanje1(polje_brojeva, 100, trazenibroj);

	if (nadiMiBroj == -1) {
		cout << "Broja nema";
	}
	else {
		cout << "Trazeni broj se nalazi na mjestu '" << nadiMiBroj << "' u polju. To polje ima vrijednost: " << polje_brojeva[nadiMiBroj];
	}

	cout << endl << endl;
	linearno_pretrazivanje2(polje_brojeva, 100, trazenibroj);

}


