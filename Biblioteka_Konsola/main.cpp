#include <iostream>
#include "Egzemplarz.h"
#include "Katalog.h"
#include "Ksiazka.h"
#include "MenadzerBiblioteki.h"


using namespace std;
int main()
{
	Katalog* SciFi = new Katalog();
	Ksiazka*  KsiazkaTestowa = new Ksiazka("12345-12345-A12", "Ksiazka Testowa", "Mariusz Jurkiewicz", 1994, "Krysicki&Wlodarski Studio",
		"Opis", "Fantastyczna literatura", "Pierwszy rozdzial ksiazki testowej");
	SciFi->DodajKsiazke(KsiazkaTestowa);
	MenadzerBiblioteki* Menadzer = new MenadzerBiblioteki();
	Menadzer->DodajKatalog(SciFi);

	Menadzer->WyswietlMenuGlowne();

	delete Menadzer;
	return 0;
}