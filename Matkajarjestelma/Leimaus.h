#pragma once
#include "stdafx.h"
#include <memory>
#include <ctime>
#include <chrono>

class Leimaus
{
private:
	std::unique_ptr<string> leimaajanNimi;
	std::unique_ptr<std::time_t> leimausAika;
public:
	Leimaus();
	Leimaus(string nimi);
	string getLeimaajaNimi();
	std::time_t getLeimausAika();
	~Leimaus();
};

