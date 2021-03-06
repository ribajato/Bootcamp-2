// Test2
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>// za pisanje-citanje u-iz datoteke

using namespace std;

struct pacijent
{
	int MBO;
	string ime;
	string prezime;
	vector<string>lijekovi;
};

void izbornik(int izbor);
void odabir_Prijava_Odjava(int izb);
pacijent Novi_Pacijent();
void Ucitavanje_Pacijenata();

int main()
{
	int unos;

	do
	{
		system("cls");
		Ucitavanje_Pacijenata();
		cout << "                                     LIJECNICKA  ORDINACIJA \n\n";
		cout << "1 - Unos novih pacijenata u kartoteku\n2 - Ispis svih pacijenata\n3 - Pretraga pacijenata po MBO\n";
		cout << "4 - Sustav cekaonice\n5 - Dodavanje recepata za lijekove na korisnicki racun pacijenta\n";
		cout << "0 - Izlaz iz programa \n\n";
		cout << "Unesite vas odabir: ";
		cin >> unos;
		izbornik(unos);
		
	} while (unos != 0);
}

void izbornik(int izbor)
{
	switch (izbor)
	{

	case 1:
		cout << "Izabrao si: 1 -  Unos novih pacijenata u kartoteku \n";
		Novi_Pacijent();
		system("pause");
		break;
	case 2:
		cout << "Izabrao si: 2 - Ispis svih pacijenata\n";
	//	Ispis_Pacijenata();
		system("pause");
		break;
	case 3:
		cout << "Izabrao si: 3 - Pretraga pacijenata po MBO\n";
		//	Pretraga_Pacijenata();
		system("pause");
		break;
	case 4:
		int izbor;
		do
		{
			system("cls");
			cout << "                                     LIJECNICKA  ORDINACIJA \n\n";
			cout << "Izabrao si: 4 - Sustav cekaonice:\n\n";
			cout << "1 - Prijava pacijenta \n";
			cout << "2 - Odjava pacijenta \n";
			cout << "3 - Povratak na glavni izbornik \n\n";
			cout << "Unesite svoj izbor: ";
			cin >> izbor;
			odabir_Prijava_Odjava(izbor);
		} while (izbor != 3);
		break;
	case 5:
		cout << "Izabrao si: 5 - Dodavanje recepata za lijekove na korisnicki racun pacijenta\n";
		//	Pretraga_Pacijenata();
		system("pause");
		break;

	default:
		cout << "Niste unijeli ispravan izbor!" << endl;
		system("pause");
	}
}

void odabir_Prijava_Odjava(int izb)
{
	switch (izb)
	{
	case 1:
		cout << "Izabrao si: 1 - Prijava pacijenta \n";
		system("pause");
		//	Prijava_Pacijenta();
		break;
	case 2:
		cout << "Izabrao si: 2 - Odjava pacijenta \n";
		system("pause");
		//	Odjava_Pacijenta();
		break;
	case 3:
	
		break;
	default:
		cout << "Niste unijeli ispravan izbor!" << endl;
		system("pause");
	}
}

pacijent Novi_Pacijent()
{
	string lijek;
	pacijent p;

	cout << "Unesite MBO pacjenta: ";
	cin >> p.MBO;
	cout << "Unesite ime: ";
	cin >> p.ime;
	cout << "Unesite prezime: ";
	cin >> p.prezime;
	cout << "Ukoliko pacijent ne koristi vise lijekova upisite slovo N:\n";
	do
	{
		cout << "Unesite lijekove koje pacijent koristi: \n";
		cin >> lijek;
		if (lijek != "N" && lijek != "n")
		{
			p.lijekovi.push_back(lijek);
		}
	} while (lijek != "N" && lijek != "n");
	ofstream korisnici;
	korisnici.open("pacijenti.txt", ios::out | ios::app);
	korisnici << to_string (p.MBO) +"\n" + p.ime + "\n" + p.prezime + "\n";
	for (int i = 0; i < p.lijekovi.size(); i++)
	{
		korisnici << p.lijekovi[i] << "\n";
	}
	korisnici << "-" << endl;
	return p;
}

void Ucitavanje_Pacijenata()
{
	vector<pacijent>pacijenti;
	pacijent p;
	ifstream input;
	input.open("pacijenti.txt");
	string MBO, lijek;

	while (input)
	{
		getline(input, MBO);
		if (MBO == "")
		{
			continue;
		}
		else {
			p.MBO = stoi(MBO);
		}
		getline(input, p.ime);
		getline(input, p.prezime);
		vector<string>medicina;
		do
		{
			getline(input, lijek);
			if (lijek != "-")
			{
				medicina.push_back(lijek);
			}
		} while (lijek != "-");
		p.lijekovi = medicina;
		pacijenti.push_back(p);
		if (input.eof())
		{
			break;
		}
	}

}


