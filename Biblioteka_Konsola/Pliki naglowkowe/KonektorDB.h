#pragma once
#include <iostream>
#include <mysql.h>
#include <sstream>
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
	void ShowTables();

	/** MySQL Destructor */
	~KonektorDB();
};