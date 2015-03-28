#include <iostream>
#include "Egzemplarz.h"
#include "Katalog.h"
#include "Ksiazka.h"
#include "MenadzerBiblioteki.h"


using namespace std;
int main()
{
	MenadzerBiblioteki* Menadzer = new MenadzerBiblioteki();
	Menadzer->WyswietlMenuGlowne();

	delete Menadzer;
	return 0;
}