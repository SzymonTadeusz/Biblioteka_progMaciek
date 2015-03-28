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
			cout << "Katalogi: " << endl;
			system("PAUSE");
			break;
		case 2:
			cout << "Ksiazki: " << endl;
			system("PAUSE");
			break;
		case 0:
			exit(0);
			break;
		default: break;
		}
	}
}