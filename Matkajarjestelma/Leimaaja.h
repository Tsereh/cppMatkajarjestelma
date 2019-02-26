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
	std::deque<string> leimaukset;
	int linjaNro;
public:
	Leimaaja();
	void leimaa(std::unique_ptr<Matkakortti> kortti, Matkatyyppi tyyppi);
	void tulostaLeimaukset();
	~Leimaaja();
};

