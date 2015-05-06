#pragma once
#include <vector>
#include <list>
#include <iostream>

#include "Ksiazka.h"

using namespace std;

 // Katalog dzieli ca�� literatur� na:
 //* - pi�kn�
 //* - naukow�
 //* - beletrystyk�
class Katalog {
private:
	string NazwaKatalogu;
	Ksiazka* ListaKsiazek[100];
	std::vector<Katalog*> ListaKsiazek2;

public:
	Katalog();
	~Katalog();
	void WyswietlKatalog();
	Ksiazka* WyszukajKsiazke(string nazwKsi);
	void WyswietlKsiazke(int indKsi);
	void DodajKsiazke(Ksiazka* DoDodania);
	string GetNazwa();
};
