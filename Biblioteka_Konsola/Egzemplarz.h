#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>


class Egzemplarz {
private:
	int NrKatalogowy;
	bool CzyWypozyczona;
	int DoKiedyWypozyczona;

public:
	void wypozycz();
};
