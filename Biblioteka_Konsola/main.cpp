#include <iostream>
#include "Egzemplarz.h"
#include "Katalog.h"
#include "Ksiazka.h"
#include "MenadzerBiblioteki.h"


using namespace std;
int main()
{
	int decyzja = 1;
	while (decyzja != 0)
	{
		system("CLS");
		cout << "****Witamy w programie bibliotecznym****\n";
		cout << "Co chcesz zrobic?" << endl;
		cout << "1. Przegladanie katalogow" << endl;
		cout << "2. Przegladanie ksiazek w danym katalogu" << endl;
		cout << "0. Wyjscie z programu" << endl << endl;
		cout << "Twoja decyzja: ";
		cin >> decyzja;
		switch (decyzja)
		{
		case 1:  cout << "katalogi: " << endl;
			system("PAUSE");
			break;
		case 2:  cout << "ksiazki: " << endl;
			system("PAUSE");
			break;
		case 0:  exit(0);
			break;
		default: break;
		}
	}
	return 0;
}