// 1. zadatak - pojmovi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector <string> pojmovi;
	vector <int> pozicije;
	ifstream krcanje;
	string pojam;
	krcanje.open("pojmovi.txt");
	while (krcanje) {
		krcanje >> pojam;
		pojmovi.push_back(pojam);
	}
	krcanje.close();

	for (int i = 0; i < pojmovi.size(); i++) {
		cout << pojmovi[i] << endl;
	}

	cout << "Unesite pojam za pretrazivanje: ";
	cin >> pojam;
	int pozicija = -1;
	for (int i = 0; i < pojmovi.size(); i++) {
		if (pojam == pojmovi[i]) {
			pozicija = i;
			break;
		}
	}

	if (pozicija == -1) {
		cout << "Trazeni pojam nije nadjen!" << endl;
	}
	else {
		cout << "Trazeni pojam je na poziciji " << pozicija << endl;
	}

	cout << endl;
	cout << "Unesite pojam za pretrazivanje svih pozicija: ";
	cin >> pojam;
	for (int i = 0; i < pojmovi.size(); i++) {
		if (pojam == pojmovi[i]) {
			pozicije.push_back(i);
		}
	}

	if (pozicije.empty()) {
		cout << "Trazeni pojam nije nadjen!" << endl;
	}
	else {
		cout << "Trazeni pojam je na poziciji ";
		for (int i = 0; i < pozicije.size(); i++) {
			cout << pozicije[i] << " ";
		}
	}
}