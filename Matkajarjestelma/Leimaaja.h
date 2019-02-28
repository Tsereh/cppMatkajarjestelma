#pragma once
#include "stdafx.h"
#include <deque>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "Leimaus.h"


class Leimaaja
{
private:
	std::deque<string> leimaajaNimet;
	std::deque<string> leimausAjat;
	int linjaNro;
public:
	Leimaaja();
	void leimaa(Matkakortti& kortti, Matkatyyppi tyyppi);
	void tulostaLeimaukset();
	~Leimaaja();
	Leimaaja &operator<<(Matkakortti& kortti);
};

