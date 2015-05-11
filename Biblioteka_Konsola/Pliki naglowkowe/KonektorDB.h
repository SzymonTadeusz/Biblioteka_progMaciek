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
	void WykonajZapytanie(string zapytanie, MenadzerBiblioteki menadzer);

	/** MySQL Destructor */
	~KonektorDB();
};