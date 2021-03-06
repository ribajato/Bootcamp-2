// Povezane liste

//Zadatak 1.: Napišite funkciju za prolazak (ispis) elemenata u listi
//Zadatak 2.: Napišite funkciju za brisanje elementa s kraja liste
//Zadatak 1.1:Napišite funkciju koja vraća broj elemenata u listi
//Zadatak 1.2:Nspišite funkciju za pretrživanje povezane liste (element na poziciji i koliko elemenata ima)
//Zadatak 1.3:Napiši funkciju za brisanje n-tog elementa u listi

#include "pch.h"
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

void insertElementFront(Node *&head, int value)    //dodavanje elementa na početak liste
{
	Node *temp = new Node;
	temp->value = value;
	temp->next = head;
	head = temp;
}

void insertElementEnd(Node *&head, int value)    //dodavanje elementa na kraj liste
{
	Node *n = new Node;
	n->value = value;
	n->next = nullptr;

	Node *temp = head;
	if (temp == nullptr)
	{
		temp = n;
		head = temp;
	}
	else
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = n;
	}
}

void ispisElemenataListe(Node *head)    //ispis elemenata u listi   // Zadatak 1.
{

	Node *temp = head;

	if (temp == NULL)
	{
		cout << "Lista je prazna!\n";
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->value << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
}

void deliteHead(Node *&head)  // funkcija brisanja elementa s početka liste
{
	Node *temp = head;

	if (temp != 0)
	{
		head = temp->next;
		delete temp;
	}
}

void deliteEnd(Node *&head)  // funkcija brisanja elementa s kraja liste   // Zadatak 2.
{
	Node *temp = head;

	if (temp->next == nullptr)
	{
		head = nullptr;
		delete temp;
	}
	else
	{
		Node *predzadnji = head;
		while (temp->next != nullptr) 
		{
			predzadnji = temp;
			temp = temp->next;
		}
		delete temp;
		predzadnji->next = nullptr;
	}
}

void BrojElemenata(Node *head)    //funkcija koja vraća broj elemenata u listi   // Zadatak 1.1
{
	int brojac=0;
	Node *temp = head;
	if (temp == NULL)
	{
		cout << "Broj elemenata u listi je "<< brojac << "! Lista je prazna\n";
	}
	else
	{
		while (temp != NULL)
		{
			temp = temp->next;
			brojac++;
		}
		cout << "Broj elemenata u listi je " << brojac << endl;
		
	}
}

void PretrazivanjePovezaneListe(Node *head, int vrijednost)    //funkcija koja trazi neki broj u listi i na kojem mjestu se nalazi   // Zadatak 1.2
{
	int brojac = 0;
	int brojac2 = 0;
	Node *temp = head;
	if (temp == NULL)
	{
		cout << "Trazeni broj se ne nalazi u listi!\n";
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->value== vrijednost)
			{
				cout << "Trazeni broj se nalazi na mjestu " << brojac << endl;
				brojac2++;
			}
			temp = temp->next;
			brojac++;
		}
		cout << "Trazeni broj se pojavljuje " << brojac2 << " puta\n";
		
	}
}

void BrisanjeElementa(Node *&head, int element)  // funkcija brisanja n-tog elementa iz liste   // Zadatak 1.3.
{
	Node *temp = head;
	int brojac = 1;

	if (element == brojac) {
		head = temp->next;
		delete temp;
	}
	else
	{
		Node *predzadnji = head;
		while (temp->next != nullptr && brojac != element)
		{
			predzadnji = temp;
			temp = temp->next;
			brojac++;
		}
		if (brojac == element) {
			predzadnji->next = temp->next;
			delete temp;
		}
	}
}
	


int main()
{
	Node *head = nullptr;
	int izbor, broj;
	do {
		system("cls");
		cout << "1 - Unos na pocetak liste\n2 - Unos na kraj liste\n3 - Ispis liste\n4 - Brisanje elementa s pocetka liste\n";
		cout << "5 - Brisanje elementa s kraja liste\n6 - Broj elenenata u listi\n7 - pretrazivanje povezane liste\n";
		cout << "8 - Brisanja n-tog elementa iz liste\n0 - Izlaz\n";
		cout << "Unesite svoj izbor: ";
		cin >> izbor;
		switch (izbor) {
		case 0:
			break;
		case 1:
			cout << "Unesite element: ";
			cin >> broj;
			insertElementFront(head, broj);
			break;
		case 2:
			cout << "Unesite element: ";
			cin >> broj;
			insertElementEnd(head, broj);
			break;
		case 3:
			ispisElemenataListe(head);
			cout << endl;
			system("pause");
			break;
		case 4:
			deliteHead(head);
			break;
		case 5:
			deliteEnd(head);
			break;
		case 6:
			BrojElemenata(head);
			system("pause");
			break;
		case 7:
			cout << "Unesite broj za koji provjeravate je li u listi: ";
			cin >> broj;
			PretrazivanjePovezaneListe(head, broj);
			system("pause");
			break;
		case 8:
			cout << "Unesite poziciju elementa kojeg zelite izbrisati iz liste: ";
			cin >> broj;
			BrisanjeElementa(head, broj);
			break;
		}
	} while (izbor != 0);

}


