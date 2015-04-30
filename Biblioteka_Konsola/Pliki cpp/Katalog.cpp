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

Ksiazka* Katalog::WyszukajKsiazke(string nazwKsi)
{
	string NazwaBiezacejKsiazki;
	//string NazwaBiezacejKsiazki2;
	Ksiazka* WynikPoszukiwan = NULL;
	//Ksiazka* WynikPoszukiwan2 = NULL;
	int i = 0;

	for (int j = 0; j < nazwKsi.length(); j++)
	{
		nazwKsi[j] = tolower(nazwKsi[j]);
	}

	while (WynikPoszukiwan == NULL && i < 100)
	{
		if (ListaKsiazek[i] != NULL)
		{
			NazwaBiezacejKsiazki = ListaKsiazek[i]->getTytul();
			//NazwaBiezacejKsiazki2 = ListaKsiazek2[i]->getTytul();

			for (int j = 0; j < NazwaBiezacejKsiazki.length(); j++)
			{
				NazwaBiezacejKsiazki[j] = tolower(NazwaBiezacejKsiazki[j]);
				//NazwaBiezacejKsiazki2[j] = tolower(NazwaBiezacejKsiazki2[j]);
			}

			if (NazwaBiezacejKsiazki == nazwKsi) WynikPoszukiwan = ListaKsiazek[i];
			//if (NazwaBiezacejKsiazki2 == nazwKsi) WynikPoszukiwan2 = ListaKsiazek2[i];
		}

		i++;
	}

	return WynikPoszukiwan;
}

void Katalog::DodajKsiazke(Ksiazka* DoDodania){
	int i = 0;
	while (i < 100 && this->ListaKsiazek[i] != NULL) i++; // omijaj dopóki na liœcie jest jakaœ zawartoœæ
	if (i < 100) {
		this->ListaKsiazek[i] = DoDodania;
		//this->ListaKsiazek2.push_back(DoDodania);
	}
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
	/*
	for (std::vector<Katalog*>::iterator it = this->ListaKsiazek2.begin(); it != ListaKsiazek2.end(); ++it)
		cout << "Tytul: ", this->ListaKsiazek2[it]->WyswietlKsiazke();
	*/
}

void Katalog::WyswietlKsiazke(int indKsi)
{
		if (indKsi <100 && this->ListaKsiazek[indKsi] != NULL) this->ListaKsiazek[indKsi]->WyswietlKsiazke();
		//if (indKsi <100 && this->ListaKsiazek2[indKsi] != NULL) this->ListaKsiazek2[indKsi]->WyswietlKsiazke();
}
