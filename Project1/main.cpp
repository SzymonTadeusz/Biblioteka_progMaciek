#include <iostream>
#include "Egzemplarz.h"
#include "Katalog.h"
#include "Ksiazka.h"
#include "MenadzerBiblioteki.h"


using namespace std;
int main(){
	cout << "****Witamy w programie bibliotecznym****\n";
	cout << "Co chcesz zrobic? \n 1. Przegladanie katalogow\n 2. Przegladanie ksiazek w danym katalogu\n\n Nacisnij 0 aby wyjsc z programu.\n\n Decyzja:";
	int decyzja;
	cin >> decyzja;
	switch (decyzja)
	{
	case 1 :  cout << "katalogi: "; break; 
	case 2 :  cout << "ksiazki: "; break; 
	case 0 :  exit(0); break; 
	default: cout << "niewlasciwa zmienna, program zakonczy dzialanie"; break; 
	}

	cout << endl;
	system("pause");
	return 0;
}