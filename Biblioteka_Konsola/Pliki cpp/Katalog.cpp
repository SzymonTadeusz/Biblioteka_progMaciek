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

Ksiazka* Katalog::WyszukajKsiazke(string nazwa)
{
	string NazwaBiezacejKsiazki;
	Ksiazka* WynikPoszukiwan = NULL;
	int i = 0;

	for (int j = 0; j < nazwa.length(); j++)
	{
		nazwa[j] = tolower(nazwa[j]);
	}

	while (WynikPoszukiwan == NULL && i < 100)
	{
		if (ListaKsiazek[i] != NULL)
		{
			NazwaBiezacejKsiazki = ListaKsiazek[i]->getTytul();

			for (int j = 0; j < NazwaBiezacejKsiazki.length(); j++)
			{
				NazwaBiezacejKsiazki[j] = tolower(NazwaBiezacejKsiazki[j]);
			}

			if (NazwaBiezacejKsiazki == nazwa) WynikPoszukiwan = ListaKsiazek[i];
		}

		i++;
	}

	return WynikPoszukiwan;
}

void Katalog::DodajKsiazke(Ksiazka* DoDodania){
	int i = 0;
	while (i < 100 && this->ListaKsiazek[i] != NULL) i++; // omijaj dopóki na liœcie jest jakaœ zawartoœæ
	if (i<100) this->ListaKsiazek[i] = DoDodania;
	else cout << "\nNie ma miejsca na dodanie ksiazki!\n";
}

string Katalog::GetNazwa(){
	return this->NazwaKatalogu;
}



Katalog::~Katalog()
{
}


void Katalog::WyswietlKatalog()
{
	//?
	for (int i = 0; i < 100; i++)
	{
		if (this->ListaKsiazek[i] != NULL) cout << "Tytul: ", this->ListaKsiazek[i]->WyswietlKsiazke();
	}
}

void Katalog::WyswietlKsiazke(int indKsi)
{
		if (indKsi <100 && this->ListaKsiazek[indKsi] != NULL) this->ListaKsiazek[indKsi]->WyswietlKsiazke();
}
