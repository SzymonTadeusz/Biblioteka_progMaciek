#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Katalog.h"

Katalog::Katalog()
{
	for (int i = 0; i < 100; i++)
	{
		this->ListaKsiazek[i] = NULL;
	}
}

Katalog::~Katalog()
{
}

void Katalog::WyswietlKatalog()
{
}

void Katalog::WyswietlKsiazke(int indKsi)
{
}
