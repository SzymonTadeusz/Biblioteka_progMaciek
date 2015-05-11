#pragma once
#include <vector>
#include <list>
#include <iostream>

#include "Katalog.h"

class MenadzerBiblioteki
{
	friend class KonektorDB;

private:
	Katalog* ListaKatalogow[10];
	std::vector<Katalog*> ListaKatalogow2;

public:
	// Konstruktor klasy MenadzerBiblioteki
	MenadzerBiblioteki();

	// Destruktor klasy MenadzerBiblioteki
	~MenadzerBiblioteki();

	// Funkcja WyswietlKatalogi wyswietla dostepne katalogi, np. beletrystykê, literaturê naukow¹ itp.
	void WyswietlKatalogi();

	// Funkcja WyswietlKatalog przyjmuje indeks Katalogu
	// dla obiektu w ListaKatalogow o danym indeksie wywoluje metode Katalog::WyswietlKatalog().
	void WyswietlKatalog(int indKat);

	void WyswietlKsiazke(int indKat, int indKsi);
	vector<Ksiazka*> WyszukajKsiazke(string nazwKsi);
	void WyswietlKatalog(string nazwKat);
	void WyswietlRozdzial(int indKat, int indKsi);
	void WyswietlMenuGlowne();
	void DodajKatalog(Katalog* doDodania);
};
