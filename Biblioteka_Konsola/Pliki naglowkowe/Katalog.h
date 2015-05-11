#pragma once
#include <vector>
#include <list>
#include <iostream>

#include "Ksiazka.h"

using namespace std;

 // Katalog dzieli ca³¹ literaturê na:
 //* - piêkn¹
 //* - naukow¹
 //* - beletrystykê
class Katalog {
	friend class MenadzerBiblioteki;
	friend class KonektorDB;
private:
	string NazwaKatalogu;
	Ksiazka* ListaKsiazek[100];
	std::vector<Ksiazka*> ListaKsiazek2;

public:
	Katalog();
	Katalog(string nazwaKat);
	~Katalog();
	void WyswietlKatalog();
	Ksiazka* WyszukajKsiazke(string nazwKsi);
	void WyswietlKsiazke(int indKsi);
	void DodajKsiazke(Ksiazka* DoDodania);
	string GetNazwa();
};
