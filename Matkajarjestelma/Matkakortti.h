#pragma once
#include "stdafx.h"
#define HELSINKIHINTA 3.0 // vaihtoehto 2: const float HELSINKIHINTA = 3.0; // C++:n nimetty vakio
#define SEUTUHINTA 4.8

using namespace std;

enum Matkatyyppi {HELSINKI, SEUTU};

class Matkakortti
{
string *omistajanNimi;
float *saldo;
private:
	void tarkistaMatka(float hinta);

public:
	Matkakortti();
	void alusta(string nimi, float s);
	void lataaSaldo(float s);
	void matkusta(enum Matkatyyppi tyyppi);
	void tulostaTiedot(); // ongelma: matkakortti ei suoraan saisi tulostaa kl:‰‰n
	string &palautaNimi();
	float palautaSaldo();
	~Matkakortti();
};

