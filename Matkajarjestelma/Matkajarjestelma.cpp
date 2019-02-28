// Matkajarjestelma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>


using namespace std;

std::ostream& operator<<(std::ostream& stream, const Leimaaja& leimaaja)
{
	stream << "Linjan " << std::to_string(leimaaja.linjaNro) << " viimeiset " << leimaaja.leimausAjat.size() << " leimausta:\n";
	for (int i = 0; i < leimaaja.leimaajaNimet.size(); i++) {
		stream << leimaaja.leimaajaNimet[i] << " : " << leimaaja.leimausAjat[i] << "\n";
	}
	stream << '\n';
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Matkakortti& kortti)
{
	stream << "Omistaja: " << kortti.palautaNimi() << ", Saldo: " << std::to_string(kortti.palautaSaldo());
	stream << "\n";
	return stream;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int v;
	string rivi;
	float raha;
	std::unique_ptr<Matkakortti> kortti = std::make_unique<Matkakortti>();
	Leimaaja leimaaja = Leimaaja();
	do
	{
		system("cls");
		cout <<"-------------------Matkakortin testausvalikko--------------------";
		cout <<"\n\n\n\n";
		cout << "\t\t\t\tAlusta matkakortti 1.\n";
		cout << "\t\t\t\tLataa matkakortti 2.\n";
		cout << "\t\t\t\tMatkusta Helsingissä 3.\n";
		cout << "\t\t\t\tMatkusta seudulla 4.\n";
		cout << "\t\t\t\tTulosta kortin tiedot 5.\n";
		cout << "\t\t\t\tTulosta leimaajan historia 6.\n";
		cout << "\t\t\t\tLopeta 7.\n";
		gotoxy(43,12);
		v=getIntFromStream();
		switch (v)
		{
			case 1:
				gotoxy(25, 14);
				cout << "Anna kortin omistajan nimi: ";
				getline(cin, rivi);
				cout << "Anna kortin aloitus saldo: ";
				raha = getFloatFromStream();
				kortti->alusta(rivi, raha);
			break;
			case 2:
				gotoxy(30, 14);
				cout << "Anna lisättävä saldo: ";
				raha = getFloatFromStream();
				kortti->lataaSaldo(raha);
				cin.get();
			break;
			case 3:
				gotoxy(25, 14);
//				leimaaja.leimaa(*kortti, HELSINKI);
				leimaaja << *kortti;
				cin.get();
				break;
			case 4:       //
				gotoxy(25, 14);
				leimaaja.leimaa(*kortti, SEUTU);
//				kortti->matkusta(SEUTU);
				cin.get();
			break;
			case 5:       //
//				kortti->tulostaTiedot();
				cout << *kortti;
				cin.get();
			break;
			case 6:       //
//				leimaaja.tulostaLeimaukset();
				cout << leimaaja;
				cin.get();
				break;
			case 7:       //

//				cin.get();
			break;
						
		}
	}
	while (v!=7);

	kortti.reset();

	return 0;
}



