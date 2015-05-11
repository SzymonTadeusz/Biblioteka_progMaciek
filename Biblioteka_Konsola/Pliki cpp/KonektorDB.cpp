#include "KonektorDB.h"

void KonektorDB::pobierzWartosciDoLogowania()
{
	do{
		cout << "Wpisz sciezke dostepu do bazy (zazwyczaj: localhost): ";
		getline(cin, this->server);
	} while (!cin.good());
	do{
		cout << "Wpisz nazwe pliku bazy (np. biblioteka): ";
		getline(cin, this->database);
	} while (!cin.good());
	do{
		cout << "Wpisz nazwe uzytkownika (np. root): ";
		getline(cin, this->user);
	} while (!cin.good());
	do{
		cout << "Wpisz haslo uzytkownika " << this->user << ": ";
		getline(cin, this->password);
	} while (!cin.good());
}

KonektorDB::KonektorDB()
{
	this->pobierzWartosciDoLogowania();

	connect = mysql_init(NULL);
	if (!connect)
	{
		cout << "KonektorDB Initialization Failed";
	}

	connect = mysql_real_connect(connect, server.c_str(), user.c_str(), password.c_str(), database.c_str(), 0, NULL, 0);

	if (connect)
	{
		cout << "\nConnection Succeeded\n";
	}

	else
	{
		cout << "\n!!! Connection Failed !!!\n Upewnij sie, ze usluga KonektorDB Server jest wlaczona i wpisano poprawne parametry\n";
	}
}


void KonektorDB::ShowTables()
{
	if (connect){
		/** Add KonektorDB Query */
		mysql_query(connect, "SELECT CONCAT_WS(' ',Imie, Nazwisko) From Osoba");

		i = 0;

		res_set = mysql_store_result(connect);

		my_ulonglong numrows = mysql_num_rows(res_set);

		cout << "\nDB o nazwie: " << this->database << endl;
		cout << "Zapytanie: SELECT Imie+Nazwisko FROM Osoba zwrocilo nastepujace wyniki: " << endl << endl;


		while (((row = mysql_fetch_row(res_set)) != NULL))
		{
			cout << row[i] << endl;
		}
	}
	else cout << "\nBrak polaczenia z baza, zapytanie zostalo pominiete" << endl;
}

KonektorDB :: ~KonektorDB()
{
	mysql_close(connect);
}


