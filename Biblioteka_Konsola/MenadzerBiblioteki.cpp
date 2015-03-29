#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MenadzerBiblioteki.h"

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
	if (i<10) this->ListaKatalogow[i] = DoDodania;
	else cout << "\nNie ma miejsca na dodanie katalogu!\n";
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
		case 0:
		{
		exit(0);
		break;
		}
		default: break;
		}
	}
}