// Sortiranje   - postoji više vrsta sortiranja dolje su prikazane tri vrste sortiranja a to su Bubble, Selection i Insertion
//Na stanici   https://visualgo.net/en/sorting   se može pogledati vizualno kako se vizualno izvodi koje sortiranje



#include "pch.h"
#include <iostream>
#include <cstdlib> // za srand
#include <ctime>  //


using namespace std;

void BubbleSort(int lista[], int velicina)
{
	int temp, j;
	bool bilaZamjena = true;

	for (int i = 0; bilaZamjena == true; i++)
	{
		bilaZamjena = false;
		for (j = 0; j < velicina - 1 - i; j++)
		{
			if (lista[j] > lista[j + 1])
			{
				temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
				bilaZamjena = true;
			}
		}
	}
}

void SelectionSort(int lista[], int velicina) //čim nađe manji elenent odmah ga  zamijeni  - veći elenemt za manji
{
	int min, temp, j;
	
	for (int i = 0; i<velicina-1; i++)
	{
		min = i;
		for (j = i+1; j < velicina; j++)
		{
			if (lista[j]<lista[min])
			{
				temp = lista[i];
				lista[i] = lista[j];
				lista[j] = temp;
			}
		}
		
	}
}

void SelectionSort2(int lista[], int velicina) // pregleda se cijeli niz do kraja i onda se zamijeni veći elenemt za manji
{                                              // Ovaj primjer je bolji nego SelectionSort koji se nalazi iznad ovog
	int min;
	for (int i = 0; i < velicina - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < velicina; j++)
		{
			if (lista[j] < lista[min])
			{
				min = j;
			}
		}
		int temp = lista[i];
		lista[i] = lista[min];
		lista[min] = temp;
	}
}

void InsertionSort(int lista[], int velicina) // Ovaj nacin objasnio Ivan 2
{
	int key, i, j;
	for (i = 1; i < velicina; i++)
	{
		key = lista[i];
		j = i - 1;
		while (j >= 0 && lista[j] > key)
		{
			lista[j + 1] = lista[j];
			j = j - 1;
		}
		lista[j + 1] = key;
	}
}

void InsertionSort2(int lista[], int velicina)  //Ovaj nacion objasnio Ivan 1 
{
	for (int i = 1; i < velicina; i++)
	{
		int j;
		int temp = lista[i];
		for (j=i; j>0 && lista[j-1] > temp; j--)
		{
			if (lista[j - 1] > temp)
			{
				lista[j] = lista[j - 1];
			}
		}
		lista[j] = temp;
	}
}


int main()
{
	srand(time(NULL));
	int polje_brojeva[20];
	for (int i = 0; i < 20; i++)
	{
		polje_brojeva[i] = rand() % 100 + 1;
	}
	cout << "Generirani brojevi u polju polje_brojeva su:\n";
	for (int i = 0; i < 20; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	BubbleSort(polje_brojeva, 20);
	cout << "\n\nSortirani brojevi u polju polje_brojeva koristeci BubbleSort su:\n";
	for (int i = 0; i < 20; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		polje_brojeva[i] = rand() % 100 + 1;
	}
	cout << "\nGenerirani brojevi u polju polje_brojeva su:\n";
	for (int i = 0; i < 20; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	SelectionSort2(polje_brojeva, 20);
	cout << "\n\nSortirani brojevi u polju polje_brojeva koristeci SelectionSort su:\n";
	for (int i = 0; i < 20; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 15; i++)
	{
		polje_brojeva[i] = rand() % 100 + 1;
	}
	cout << "\nGenerirani brojevi u polju polje_brojeva su:\n";
	for (int i = 0; i < 15; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	InsertionSort(polje_brojeva, 15);
	cout << "\n\nSortirani brojevi u polju polje_brojeva koristeci InsertionSort su:\n";
	for (int i = 0; i < 15; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 15; i++)
	{
		polje_brojeva[i] = rand() % 100 + 1;
	}
	cout << "\nGenerirani brojevi u polju polje_brojeva su:\n";
	for (int i = 0; i < 15; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	InsertionSort2(polje_brojeva, 15);
	cout << "\n\nSortirani brojevi u polju polje_brojeva koristeci InsertionSort2 su:\n";
	for (int i = 0; i < 15; i++)
	{
		cout << polje_brojeva[i] << " ";
	}
	cout << endl;

}

