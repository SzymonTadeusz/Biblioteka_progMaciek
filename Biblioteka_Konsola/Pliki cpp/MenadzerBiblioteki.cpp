#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../Pliki naglowkowe/MenadzerBiblioteki.h"

using namespace std;

MenadzerBiblioteki::MenadzerBiblioteki()
{
	for (int i = 0; i < 10; i++)
	{
		this->ListaKatalogow[i] = NULL;
	}
}

void MenadzerBiblioteki::DodajKatalog(Katalog* DoDodania){
	int i = 0;
	while (i < 10 && this->ListaKatalogow[i] != NULL) i++; // omijaj dopóki na liœcie jest jakaœ zawartoœæ
	if (i < 10) {
		this->ListaKatalogow[i] = DoDodania;
		this->ListaKatalogow2.push_back(DoDodania);
	}
	else cout << "\nNie ma miejsca na dodanie katalogu!\n";
}

Ksiazka* MenadzerBiblioteki::WyszukajKsiazke(string nazwKsi)
{
	Ksiazka* WynikPoszukiwan = NULL;
	//Ksiazka* WynikPoszukiwan2 = NULL;
	int i = 0;
	while (WynikPoszukiwan == NULL && i < 10)
	{
		if (this->ListaKatalogow[i] != NULL)
		{
			WynikPoszukiwan = this->ListaKatalogow[i]->WyszukajKsiazke(nazwKsi);
			//WynikPoszukiwan2 = this->ListaKatalogow2[i]->WyswietlKsiazke(nazwKsi);
		}

		i++;
	}

	return WynikPoszukiwan;
}

void MenadzerBiblioteki::WyswietlKatalog(string nazwKat)
{
	Katalog* znaleziony = NULL;
	string NazwaKataloguBiezacego;

	for (int j = 0; j < nazwKat.length(); j++)
	{
		nazwKat[j] = tolower(nazwKat[j]);
	}
	int j = 0;

	while (j < 10 && ListaKatalogow[j] != NULL && znaleziony == NULL)
	{
		if (ListaKatalogow[j] != NULL)
		{
			NazwaKataloguBiezacego = ListaKatalogow[j]->GetNazwa();
			//zamiana znakow pobranej nazwy na male litery
			for (int i = 0; i < NazwaKataloguBiezacego.length(); i++)
			{
				NazwaKataloguBiezacego[i] = tolower(NazwaKataloguBiezacego[i]);
			}
			if (NazwaKataloguBiezacego == nazwKat) znaleziony = ListaKatalogow[j];
		}
		j++;
	}

	if (znaleziony != NULL)
	{
		cout << "Znaleziono katalog o podanej nazwie. Jego zawartosc to:\n\n";
		znaleziony->WyswietlKatalog();
	}

	else
	{
		cout << "Nie znaleziono katalogu o podanej nazwie" << endl;
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
	this->ListaKatalogow[indKat]->WyswietlKsiazke(indKsi);
	//this->ListaKatalogow2[indKat]->WyswietlKsiazke(indKsi);
}

void MenadzerBiblioteki::WyswietlRozdzial(int indKat, int indKsi)
{
}

void MenadzerBiblioteki::WyswietlMenuGlowne()
{
	int decyzja = 1;
	while (decyzja != 0)
	{
		system("CLS");
		cout << "****Witamy w programie bibliotecznym****" << endl << endl;
		cout << "Co chcesz zrobic?" << endl;
		cout << "1. Przegladanie katalogow" << endl;
		cout << "2. Przegladanie ksiazek w danym katalogu" << endl;
		cout << "3. Wyszukiwanie katalogow po nazwie katalogu" << endl;
		cout << "4. Wyszukiwanie ksiazek po nazwie ksiazki" << endl;
		cout << "0. Wyjscie z programu" << endl << endl;
		cout << "Twoja decyzja: ";
		cin >> decyzja;
		switch (decyzja)
		{
		case 1:
		{
			cout << "Katalogi: \n" << endl;
			for (int i = 0; i < 1; i++)			 // i - nr katalogu
			{
				cout << i+1 << ". ";
				cout << this->ListaKatalogow[0]->GetNazwa() << endl;
				//cout << this->ListaKatalogow2[0]->GetNazwa() << endl;
			}
			system("PAUSE");
			break;
		}
		case 2:
		{
			cout << "****************************************\n";
			cout << "Ksiazki: " << endl;
			for (int i = 0; i < 1; i++)			// na razie wygl¹da œmiesznie, ale przyda siê na wiêcej katalogów i ksi¹¿ek
				for (int j = 0; j < 2; j++)		// i - nr katalogu, j - nr ksi¹¿ki w katalogu
				{
					cout << j+1 << ". ";
					this->WyswietlKsiazke(i, j); cout << endl;
					cout << "----------------------------------------\n";
				}
			system("PAUSE");
			break;
		}

		case 3:
		{			cout << "****************************************\n";
		cout << "Podaj nazwe katalogu: ";
		string podanaNazwa = "";
		cin >> podanaNazwa;
		this->WyswietlKatalog(podanaNazwa);
		system("PAUSE");
			break;
		}
		case 4:
		{			cout << "****************************************\n";
		cout << "Podaj nazwe ksiazki: ";
		string podanaNazwa = "";
		cin.sync();
		getline(std::cin, podanaNazwa);
		Ksiazka* wyswietlanaKsiazka;
		wyswietlanaKsiazka = this->WyszukajKsiazke(podanaNazwa);
		if (wyswietlanaKsiazka) wyswietlanaKsiazka->WyswietlKsiazke();
		else cout << "Brak takiej ksiazki w bazie!";
		system("PAUSE");
		break;
		}
		case 0:
		{
		exit(0);
		break;
		}
		default: break;
		}
	}
}