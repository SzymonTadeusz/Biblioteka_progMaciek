#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

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

	if(zalogowany) cout << "----------WITAMY W SYSTEMIE----------" << endl << endl;
	
	system("PAUSE");
	return 0;
}

//
//
//#include <iostream>
//#include <stdexcept>
//#include <string>
//#include <windows.h>
//using namespace std;
//
//string getpassword(const string& prompt = "Enter password> ")
//{
//	string result;
//
//	// Set the console mode to no-echo, not-line-buffered input
//	DWORD mode, count;
//	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
//	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
//
//	// Get the password string
//	WriteConsoleA(oh, prompt.c_str(), prompt.length(), &count, NULL);
//	char c;
//	while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
//	{
//		if (c == '\b')
//		{
//			if (result.length())
//			{
//				WriteConsoleA(oh, "\b \b", 3, &count, NULL);
//				result.erase(result.end() - 1);
//			}
//		}
//		else
//		{
//			WriteConsoleA(oh, "*", 1, &count, NULL);
//			result.push_back(c);
//		}
//	}
//
//	// Restore the console mode
//	SetConsoleMode(ih, mode);
//
//	return result;
//}
//
//int main()
//{
//	cout << "KUPSKO" << endl;
//	try {
//
//		string password = getpassword("Enter a test password> ");
//		cout << "\nYour password is " << password << endl;
//
//	}
//	catch (exception& e)
//	{
//		cerr << e.what();
//		return 1;
//	}
//
//	return 0;
//