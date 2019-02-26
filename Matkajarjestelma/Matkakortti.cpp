#include "stdafx.h"

using namespace std;

Matkakortti::Matkakortti()
{
}


Matkakortti::~Matkakortti()
{
}

void Matkakortti::alusta(string nimi, float s)
{
	omistajanNimi = std::unique_ptr<string>{ new string(nimi) };
	saldo = std::unique_ptr<float>{ new float(s) };
}

void Matkakortti::lataaSaldo(float s)
{
	saldo.reset(new float(*saldo + s));
	cout << "Saldoa ladattu. Saldo: " << std::to_string(*saldo);
}

bool Matkakortti::tarkistaMatka(float hinta) {
	if (*saldo >= hinta) {
		saldo.reset(new float(*saldo - hinta));
		cout << "Hyvää matkaa! Saldoa jäljellä: " << std::to_string(*saldo);
		return true;
	}
	else {
		cout << "Saldo ei riitä. Saldo: " << std::to_string(*saldo);
		return false;
	}
}

bool Matkakortti::matkusta(enum Matkatyyppi tyyppi)
{
	switch (tyyppi) {
		case HELSINKI:
			return tarkistaMatka(HELSINKIHINTA);
//			break;
		case SEUTU:
			return tarkistaMatka(SEUTUHINTA);
//			break;
	}
}

string &Matkakortti::palautaNimi()
{
	return *omistajanNimi;
}

float Matkakortti::palautaSaldo()
{
	return *saldo;
}

void Matkakortti::tulostaTiedot() {
	cout << "Omistaja: " << *omistajanNimi << ", Saldo: " << std::to_string(*saldo);
}