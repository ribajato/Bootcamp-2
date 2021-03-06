// Rekurzivne funkcije1
//1. Napiši rekurzivnu funkciju koja će brojeve ispisati od manjeg prema većem.
//2. Napiši rekurzivnu funkciju koja će brojeve ispisati od većeg prema manjem.
//4. Napiši rekurzivnu funkciju koja će za zadani broj izračunati faktorijelu. 
//   (npr. 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720)
//5. Napiši rekurzivnu funkciju koja će za zadani element u nizu izračunati Fibonaccijev broj.
//6. Ispiši Fibonaccijev niz za zadani element.




#include "pch.h"
#include <iostream>

using namespace std;

void manji_prema_vecem(int broj)   //1.
{
	if (broj > 1)
	{
		manji_prema_vecem(broj - 1);
	}
	cout << "Ispisisujem broj: manji - veci: " << broj << endl;
}	 
void veci_prema_manjem(int broj)         //2.
{
	cout << "Ispisisujem broj: veci - manji: " << broj << endl;
	broj--;
	if (broj > 0) 
	{
		veci_prema_manjem(broj);
	}
}
int fakt(int x)     // 4.
{
	if (x == 1) {
		return 1;
	}
	else {
		return x * fakt(x - 1);
	}
}

int fibonacci(int x)        //5.
{
	if (x == 0 || x == 1)
	{
		return x;
	}
	else {
			return fibonacci(x-1) + fibonacci(x-2);
	}

}

void fibbonacci_niz(int x)      //6.
{
	if (x > 0) {
		fibbonacci_niz(x - 1);
	}
	cout << fibonacci(x) << endl;
}

int main()
{
	int zadani_broj;
	cout << "Unesi zadani broj: ";
	cin >> zadani_broj;
	manji_prema_vecem(zadani_broj);
	cout << endl;
	veci_prema_manjem(zadani_broj);
	cout << "Faktorijela "<< fakt(zadani_broj) << endl;
	cout << "Fibonaccijev broj: " << fibonacci(zadani_broj);
	fibbonacci_niz(zadani_broj);
}

