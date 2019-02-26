#include "Leimaus.h"



Leimaus::Leimaus()
{
}

Leimaus::Leimaus(string nimi)
{
	leimaajanNimi = std::unique_ptr<string>{ new string(nimi) };
	leimausAika = std::unique_ptr<std::time_t>{ new std::time_t(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())) };
}

string Leimaus::getLeimaajaNimi() {
	return *leimaajanNimi;
}

std::time_t Leimaus::getLeimausAika() {
	return *leimausAika;
}


Leimaus::~Leimaus()
{
}
