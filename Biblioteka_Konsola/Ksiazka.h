#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Egzemplarz.h"

class Ksiazka {
private:
	char ISBN[15];
	std::string Tytul;
	std::string Autor;
	int RokWydania;
	std::string Wydawnictwo;
	std::string Opis;
	std::string Typ;
	std::string Gatunek[5];
	Egzemplarz ListaEgz[20];
	std::string PierwszyRozdz;
public:
	void WyswietlKsiazke();
	void WyswietlRozdzial();
};
