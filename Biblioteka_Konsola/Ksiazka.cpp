#include <vector>
#include <list>
#include <iostream>

#include "Ksiazka.h"

string Ksiazka::getTytul() { return this->Tytul; }

string Ksiazka::getAutor() { return this->Autor; }

string Ksiazka::getPierwszyRozdzial() { return this->PierwszyRozdz; }

void Ksiazka::WyswietlKsiazke()
{
//	if (!(this->Tytul.empty() && this->Autor.empty() && this->Wydawnictwo.empty()))
	cout << "Tytul: ", this->getTytul(), cout << " Autor: ", this->getAutor(); cout << "\nWydawnictwo: "; this->Wydawnictwo; cout << " Rok: "; this->RokWydania, cout <<"\n";
		cout << "\nCzy chcesz wyswietlic jej 1. rozdzial? 0 jesli nie: ";
		char dec = 0;
		cin >> dec;
		if (dec) this->getPierwszyRozdzial();
}

void Ksiazka::WyswietlRozdzial()
{
	cout << "Tytul: "; cout << this->getTytul().c_str(), cout << " Autor: ", this->getAutor(), "\nI rozdz.: ", this->getPierwszyRozdzial();
}

Ksiazka::Ksiazka(char _ISBN[15], string _Tytul, string _Autor, int _RokWyd, string _Wydawnictwo){
	for (int i = 0; i < 15; i++)
	{
		this->ISBN[i] = _ISBN[i];
	}
	this->Tytul = _Tytul;
	this->Autor = _Autor;
	this->RokWydania = _RokWyd;
	this->Wydawnictwo = _Wydawnictwo;
	for (int i = 0; i < 5; i++)
	{
		this->Gatunek[i] = "0";
	}
		for (int i = 0; i < 10; i++)
	{
		this->ListaEgz[i] = Egzemplarz();
	}
}

Ksiazka::Ksiazka(char _ISBN[15], string _Tytul, string _Autor, int _RokWyd, string _Wydawnictwo,
	string _Opis, string _Typ, string _Gatunek[], Egzemplarz _ListaEgz[], string _PierwszyRozdz){
	for (int i = 0; i < 15; i++)
	{
		this->ISBN[i] = _ISBN[i];
	}
	this->Tytul = _Tytul;
	this->Autor = _Autor;
	this->RokWydania = _RokWyd;
	this->Wydawnictwo = _Wydawnictwo;
	this->Opis = _Opis;
	this->Typ = _Typ;
	this->PierwszyRozdz = _PierwszyRozdz;
	for (int i = 0; i < 5; i++)
	{
		this->Gatunek[i] = "0";
	}
	for (int i = 0; i < 10; i++)
	{
		this->ListaEgz[i] = Egzemplarz();
	}
}
Ksiazka::Ksiazka(char _ISBN[15], string _Tytul, string _Autor, int _RokWyd, string _Wydawnictwo,
	string _Opis, string _Typ, string _PierwszyRozdz){
	for (int i = 0; i < 15; i++)
	{
		this->ISBN[i] = _ISBN[i];
	}
	this->Tytul = _Tytul;
	this->Autor = _Autor;
	this->RokWydania = _RokWyd;
	this->Wydawnictwo = _Wydawnictwo;
	this->Opis = _Opis;
	this->Typ = _Typ;
	this->PierwszyRozdz = _PierwszyRozdz;
	for (int i = 0; i < 5; i++)
	{
		this->Gatunek[i] = "0";
	}
	for (int i = 0; i < 10; i++)
	{
		this->ListaEgz[i] = Egzemplarz();
	}
}

