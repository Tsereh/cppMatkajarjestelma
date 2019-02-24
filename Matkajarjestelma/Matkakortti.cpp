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
	omistajanNimi = nimi;
	saldo = s;
}

void Matkakortti::lataaSaldo(float s)
{
	saldo = saldo + s;
	cout << "Saldoa ladattu. Saldo: " << std::to_string(saldo);
}

void Matkakortti::tarkistaMatka(float hinta) {
	if (saldo >= hinta) {
		saldo = saldo - hinta;
		cout << "Hyv�� matkaa! Saldoa j�ljell�: " << std::to_string(saldo);
	}
	else {
		cout << "Saldo ei riit�. Saldo: " << std::to_string(saldo);
	}
}

void Matkakortti::matkusta(enum Matkatyyppi tyyppi)
{
	switch (tyyppi) {
		case HELSINKI:
			tarkistaMatka(1.10);
			break;
		case SEUTU:
			tarkistaMatka(2.20);
			break;
	}
}

string &Matkakortti::palautaNimi()
{
	return omistajanNimi;
}

float Matkakortti::palautaSaldo()
{
	return saldo;
}

void Matkakortti::tulostaTiedot() {
	cout << "Omistaja: " << omistajanNimi << ", Saldo: " << std::to_string(saldo);
}