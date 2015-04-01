#include <vector>
#include <list>
#include <iostream>

#include "../Pliki naglowkowe/Egzemplarz.h"

Egzemplarz::Egzemplarz()
{
	this->NrKatalogowy = 0;
	this->DoKiedyWypozyczona = 0;
	this->CzyWypozyczona = false;
}

Egzemplarz::~Egzemplarz()
{
}

void Egzemplarz::wypozycz()
{
}
