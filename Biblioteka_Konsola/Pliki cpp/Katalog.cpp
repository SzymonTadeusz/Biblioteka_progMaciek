#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../Pliki naglowkowe/Katalog.h"

Katalog::Katalog()
{
	for (int i = 0; i < 100; i++)
	{
		this->ListaKsiazek[i] = NULL;
	}
	this->NazwaKatalogu = "Katalog";
}

Katalog::Katalog(string Nazwa)
{
	for (int i = 0; i < 100; i++)
	{
		this->ListaKsiazek[i] = NULL;
	}
	this->NazwaKatalogu = Nazwa;
}

Ksiazka* Katalog::WyszukajKsiazke(string nazwKsi)
{
	string NazwaBiezacejKsiazki;
	Ksiazka* WynikPoszukiwan = NULL;
	int i = 0;

	for (unsigned int j = 0; j < nazwKsi.length(); j++)
	{
		nazwKsi[j] = tolower(nazwKsi[j]);
	}

	while (WynikPoszukiwan == NULL && i < 100)
	{
		if (ListaKsiazek2[i] != NULL)
		{
			NazwaBiezacejKsiazki = ListaKsiazek2[i]->getTytul();

			for (unsigned int j = 0; j < NazwaBiezacejKsiazki.length(); j++)
			{
				NazwaBiezacejKsiazki[j] = tolower(NazwaBiezacejKsiazki[j]);
			}

			if (NazwaBiezacejKsiazki == nazwKsi) WynikPoszukiwan = ListaKsiazek2[i];
		}

		i++;
	}

	return WynikPoszukiwan;
}

void Katalog::DodajKsiazke(Ksiazka* DoDodania){
		this->ListaKsiazek2.push_back(DoDodania);
}

string Katalog::GetNazwa(){
	return this->NazwaKatalogu;
}



Katalog::~Katalog()
{
}


void Katalog::WyswietlKatalog()
{
	for each (Ksiazka* ks in this->ListaKsiazek2)
	{
		cout << "Tytul: ", ks->WyswietlKsiazke();
	}
}

void Katalog::WyswietlKsiazke(int indKsi)
{
		this->ListaKsiazek2[indKsi]->WyswietlKsiazke();
}
