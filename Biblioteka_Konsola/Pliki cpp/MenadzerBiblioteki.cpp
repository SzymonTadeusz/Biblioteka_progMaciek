#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../Pliki naglowkowe/MenadzerBiblioteki.h"
#include "../Pliki naglowkowe/KonektorDB.h"

using namespace std;

MenadzerBiblioteki::MenadzerBiblioteki()
{
	for (int i = 0; i < 10; i++)
	{
		this->ListaKatalogow[i] = NULL;
	}
}

void MenadzerBiblioteki::DodajKatalog(Katalog* DoDodania){
	this->ListaKatalogow2.push_back(DoDodania);
}

vector<Ksiazka*> MenadzerBiblioteki::WyszukajKsiazke(string nazwKsi)
{
	vector<Ksiazka*> WynikPoszukiwan;

	for each (Katalog* kat in this->ListaKatalogow2)
	{
		for each (Ksiazka* ks in kat->ListaKsiazek2)
			if (ks->getTytul().find(nazwKsi) != string::npos) WynikPoszukiwan.push_back(ks);
	}

	return WynikPoszukiwan;
}

void MenadzerBiblioteki::WyswietlKatalog(string nazwKat)
{	
	vector<Katalog*> zbiorKatalogow;

	for each (Katalog* kat in this->ListaKatalogow2)
		if (kat->GetNazwa().find(nazwKat) != string::npos) zbiorKatalogow.push_back(kat);
	
	if (zbiorKatalogow.empty()) cout << "Nie znaleziono katalogu o podanej nazwie." << endl;
	else{
		int decyzja;
		cout << "Znaleziono katalog(i) o podanej nazwie\nczy chcesz wyswietlic zawartosc: 1 - tak, 0 - nie: ";
		cin >> decyzja;
		if (decyzja)
		for each (Katalog* kat in zbiorKatalogow)
			kat->WyswietlKatalog();
		}
}

MenadzerBiblioteki::~MenadzerBiblioteki()
{
}

void MenadzerBiblioteki::WyswietlKatalogi()
{	
}

void MenadzerBiblioteki::WyswietlKatalog(int indKat)
{
}

void MenadzerBiblioteki::WyswietlKsiazke(int indKat, int indKsi)
{
	this->ListaKatalogow2[indKat]->WyswietlKsiazke(indKsi);
}

void MenadzerBiblioteki::WyswietlRozdzial(int indKat, int indKsi)
{
}

void MenadzerBiblioteki::WyswietlMenuGlowne()
{
	KonektorDB konektor; //w konstruktorze wywolywana jest metoda pobieraj¹ca dane uzytkownika
	cout << "Nacisnij dowolny klawisz aby kontynuowac";
	getchar();
	int decyzja = 1;
	while (decyzja != 0)
	{
		cin.sync(); //wyczysc bufor, jesli sa w nim jakies smieci
		system("CLS");
		cout << "****Witamy w programie bibliotecznym****" << endl << endl;
		cout << "Co chcesz zrobic?" << endl;
		cout << "1. Przegladanie katalogow" << endl;
		cout << "2. Przegladanie ksiazek w danym katalogu" << endl;
		cout << "3. Wyszukiwanie katalogow po nazwie katalogu" << endl;
		cout << "4. Wyszukiwanie ksiazek po nazwie ksiazki" << endl;
		cout << "0. Wyjscie z programu" << endl << endl;
		cout << "Twoja decyzja: ";
		while (!(cin >> decyzja)) //dopóki podawane s¹ b³êdne dane
		{
			cout << "Podaj poprawna wartosc - cyfre od 0 do 4. Twoja decyzja: ";
			cin.clear(); //kasowanie flagi b³êdu
			cin.sync(); //kasowanie zbêdnych znaków
		}
		cin.sync(); //wyczysc bufor, jesli sa w nim jakies smieci
		switch (decyzja)
		{
		case 1:
		{
			konektor.ListujKatalogi(this);
			cout << "Katalogi: \n" << endl;
			for each(Katalog* kat in this->ListaKatalogow2)
				cout <<  kat->GetNazwa() << endl;
			system("PAUSE");
			break;
		}
		case 2:
		{
			cout << "****************************************\n";
			cout << "Ksiazki: " << endl;

			for each (Katalog* kat in this->ListaKatalogow2)
			{
				kat->WyswietlKatalog();
			}
			system("PAUSE");
			break;
		}

		case 3:
		{
		cout << "****************************************\n";
		cout << "Podaj nazwe katalogu: ";
		string podanaNazwa = "";
		cin >> podanaNazwa;
		this->WyswietlKatalog(podanaNazwa);
		system("PAUSE");
			break;
		}
		case 4:
		{
		cout << "****************************************\n";
		cout << "Podaj nazwe ksiazki: ";
		string podanaNazwa = "";
		cin.sync();
		getline(std::cin, podanaNazwa);
		vector<Ksiazka*> zbior;
		//zbior = this->WyszukajKsiazke(podanaNazwa);
		zbior = konektor.WyszukajKsiazke(podanaNazwa);
		if (zbior.empty()) cout << "Brak takiej ksiazki w bazie!";
		else 
			for each (Ksiazka* ks in zbior)
			{
			  ks->WyswietlKsiazke();
			}
		system("PAUSE");
		break;
		}
		case 0:
		{
		konektor.~KonektorDB();
		exit(0);
		break;
		}
		default: break;
		}
	}
}