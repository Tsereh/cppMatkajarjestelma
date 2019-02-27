#include "Leimaus.h"



Leimaus::Leimaus()
{
}

Leimaus::Leimaus(string nimi)
{
	leimaajanNimi = nimi;
	leimausAika = std::time_t(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
}

string Leimaus::getLeimaajaNimi() {
	return leimaajanNimi;
}

std::time_t Leimaus::getLeimausAika() {
	return leimausAika;
}


Leimaus::~Leimaus()
{
}
