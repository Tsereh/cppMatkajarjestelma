#pragma once
#include "stdafx.h"
#include <memory>
#include <ctime>
#include <chrono>

class Leimaus
{
private:
	string leimaajanNimi;
	std::time_t leimausAika;
public:
	Leimaus();
	Leimaus(string nimi);
	string getLeimaajaNimi();
	std::time_t getLeimausAika();
	~Leimaus();
};

