#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Ksiazka.h"

using namespace std;

 //Katalog dzieli ca³¹ literaturê na:
 //* - piêkn¹
 //* - naukow¹
 //* - beletrystykê
class Katalog {
private:
	string NazwaKatalogu;
	Ksiazka* ListaKsiazek[100];

public:
	Katalog();
	~Katalog();
	void WyswietlKatalog();
	void WyswietlKsiazke(int indKsi);
};
