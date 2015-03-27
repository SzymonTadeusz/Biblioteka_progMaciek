#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Katalog.h"

class MenadzerBiblioteki
{
private:
	Katalog ListaKatalogow[10];


public:
	/**
	 * Funkcja wyswietla dostepne katalogi, np. beletrystykê, literaturê naukow¹ itp.
	 * 
	 */
	void WyswietlKatalogi();

	/**
	 * Przyjmuje indeks i, dla obiektu w ListaKatalogow o danym indeksie wywoluje metode Katalog::WyswietlKatalog().
	 */
	void WyswietlKatalog(int indKat);

	void WyswietlKsiazke(int indKat, int indKsi);

	void WyswietlRozdzial(int indKat, int indKsi);

};
