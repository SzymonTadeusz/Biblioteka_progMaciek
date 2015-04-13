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
