// strukture podataka is STL-a
//
//Zadatak:
//1. Napravi program koji će za korisnikov unos provjeriti je li unos palindrom (koristite odgovarajuću strukturu podataka).
//(Obrtaljka, odnosno palindrom je igra riječi u kojoj se čitanjem jedne riječi ili čitave rečenice obrnutim redom dobiva isto značenje kao i pravilnim čitanjem. )
//


#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

void stog(int a)
{
	stack<int> lastinFirstout;

	for (int i=1; i<=a; i++)
	{ 
		int broj;
		cout << "\nUpisi broj _" << i << " :";
		cin >> broj;
		lastinFirstout.push(broj);
	}
	for (int i = 1; i <= a; i++, lastinFirstout.pop())
	{
		cout << lastinFirstout.top();
	}
}
int main()
{
	int a;
	cout << "Upisi koliko zelis brojeva napunit u stog: ";
	cin >> a;
	stog(a);
}

