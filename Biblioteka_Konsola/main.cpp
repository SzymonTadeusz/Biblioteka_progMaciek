#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

//!!
//UWAGA ROBIE NIESAMOWICIE WA¯N¥ ZMIANÊ W KODZIE!!
//!!

using namespace std;

//w tej linijce zrobiê jak¹œ zmianê
int main(void)
{
	fstream plik;
	string login;
	string haslo;
	char c;
	int StarNum = 0;
	int cntStar;
	bool zalogowany = false;
	int licznik = 3;

	while(zalogowany == false && licznik > 0)
	{
		system("CLS");
		cout << "Podaj login: ";
		cin >> login;
		cout << "Podaj haslo: ";
		cin >> haslo;

		// stad wywalilem pare smieci
		
		plik.open("users.dat", std::ios::in | std::ios::out );
		if(plik.good() == true)
		{
			string loginPlik;
			string hasloPlik;
			while(zalogowany==false && !plik.eof())
			{
				getline(plik,loginPlik,'#');
				getline(plik,hasloPlik);
				if(login==loginPlik && haslo==hasloPlik) zalogowany = true;
			}
			plik.close();
		}
		licznik--;
	}

	system("CLS");
	if(!zalogowany)
	{
		cout << "WYKORZYSTANO LIMIT PROB LOGOWANIA!" << endl;
		cout << "PROGRAM ZOSTANIE ZAMKNIETY!" << endl << endl;
		system("PAUSE");
		return 10;
	}

	if(zalogowany) cout << "----------WITAMY W SYSTEMIE----------" << endl << "Synu, nawet nie masz pojecia, na jak nieograniczone mozliwosci wlasnie trafiles" << endl;
	
	system("PAUSE");
	return 0;
}
//wyrzucone obce œmieci