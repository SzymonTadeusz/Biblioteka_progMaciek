#include "..\Pliki naglowkowe\KonektorDB.h"

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


void KonektorDB::ListujKatalogi(MenadzerBiblioteki* menadzer)
{
	if (connect){
		/** Add KonektorDB Query */
		mysql_query(connect, "SELECT NazwaKatalogu from Katalog");

		i = 0;

		res_set = mysql_store_result(connect);

		my_ulonglong numrows = mysql_num_rows(res_set);
		int num_fields = mysql_num_fields(res_set);

		cout << "\nDB o nazwie: " << this->database << endl;

		while (((row = mysql_fetch_row(res_set)) != NULL))
		{
			for (int i = 0; i < num_fields; i++)
			{
				//if (i == 0)
				//{
				while (field = mysql_fetch_field(res_set))

					printf("\n");
				//}
				Katalog* wstawiany = new Katalog();
				wstawiany->NazwaKatalogu = row[i];
				menadzer->ListaKatalogow2.push_back(wstawiany);
			}
		}
		mysql_free_result(res_set);
	}
	else cout << "\nBrak polaczenia z baza, zapytanie zostalo pominiete" << endl;
}



vector<Ksiazka*> KonektorDB::WyszukajKsiazke(string nazwaKsiazki)
{
	vector<Ksiazka*> zbior;
	if (connect){
		/** Add KonektorDB Query */
		string zapytanie = "select tytul, concat_ws(' ',Imie, Nazwisko) as Autor, Rokwydania ";
		zapytanie += "from ksiazka k join autorzytytulu aut on k.idksiazki = aut.idksiazki join autor a on aut.idautora = a.idautora ";
		zapytanie += "Where tytul LIKE \"%";
		zapytanie += nazwaKsiazki;
		zapytanie += "%\"";
		cout << zapytanie;
		mysql_query(connect, zapytanie.c_str());
		i = 0;

		res_set = mysql_store_result(connect);
		if (res_set != NULL)
		{

			my_ulonglong numrows = mysql_num_rows(res_set);
			int num_fields = mysql_num_fields(res_set);

			cout << "\nDB o nazwie: " << this->database << endl;

			while (((row = mysql_fetch_row(res_set)) != NULL))
			{
				Ksiazka* wstawiana = new Ksiazka();

				for (int i = 0; i < num_fields; i++)
				{
						
					//while (field = mysql_fetch_field(res_set))
					//{
					//}

						if (i==0)
							wstawiana->Tytul = row[i];
						if (i==1)
							wstawiana->Autor = row[i];
						if (i==2)
							wstawiana->RokWydania = atoi(row[i]);
						printf("%s  ", row[i] ? row[i] : "NULL");

				}
					printf("\n");
					zbior.push_back(wstawiana);
			}
			mysql_free_result(res_set);
		}
	}
	else cout << "\nBrak polaczenia z baza, zapytanie zostalo pominiete" << endl;

	return zbior;
}

KonektorDB :: ~KonektorDB()
{
	mysql_close(connect);
}


