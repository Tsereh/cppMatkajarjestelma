// Matkajarjestelma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int v;
	string rivi;
	float raha;
	Matkakortti kortti;
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
		cout << "\t\t\t\tLopeta 6.\n";
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
				kortti.alusta(rivi, raha);
			break;
			case 2:
				gotoxy(30, 14);
				cout << "Anna lisättävä saldo: ";
				raha = getFloatFromStream();
				kortti.lataaSaldo(raha);
				cin.get();
			break;
			case 3:
				gotoxy(25, 14);
				kortti.matkusta(HELSINKI);
				cin.get();
				break;
			case 4:       //
				gotoxy(25, 14);
				kortti.matkusta(SEUTU);
				cin.get();
			break;
			case 5:       //
				kortti.tulostaTiedot();
				cin.get();
			case 6:       //

//				cin.get();
			break;
						
		}
	}
	while (v!=6);
	return 0;
}



