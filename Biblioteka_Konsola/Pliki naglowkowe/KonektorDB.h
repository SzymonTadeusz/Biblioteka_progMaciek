#pragma once
#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <sstream>
#include "..\Pliki naglowkowe\MenadzerBiblioteki.h"

using namespace std;

class KonektorDB
{
protected:
	/** MySQL connectivity Variables */
	MYSQL *connect;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	MYSQL_FIELD *field;

	unsigned int i;
	string user;
	string password;
	string database;
	string server;



public:

	void pobierzWartosciDoLogowania();
	/** MySQL Constructor */
	KonektorDB();

	/** Function to show tables in database */
	void ListujKatalogi(MenadzerBiblioteki* menadzer);
	vector<Ksiazka*> WyszukajKsiazke(string nazwaKsiazki);
	/** MySQL Destructor */
	~KonektorDB();
};