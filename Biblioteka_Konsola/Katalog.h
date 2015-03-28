#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Ksiazka.h"


 /* Katalog dzieli ca�� literatur� na:
 * - pi�kn�
 * - naukow�
 * - beletrystyk�*/
class Katalog {
private:
	std::string NazwaKatalogu;
	Ksiazka ListaKsiazek[100];

public:
	void WyswietlKatalog();
	void WyswietlKsiazke(int indKsi);
};
