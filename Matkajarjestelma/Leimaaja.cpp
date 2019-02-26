#include "Leimaaja.h"


Leimaaja::Leimaaja()
{
	cout << "Syötä linjan numero: ";
	linjaNro = getIntFromStream();
}

void Leimaaja::leimaa(std::unique_ptr<Matkakortti> kortti, Matkatyyppi matkatyyppi) {
	if (kortti->matkusta(matkatyyppi)) {
		leimaukset.push_front(kortti->palautaNimi());//(Leimaus(kortti.palautaNimi()));

		if (leimaukset.size() > 5) {
			leimaukset.pop_back();
		}
	}
}

void Leimaaja::tulostaLeimaukset() {
	cout << "Linjan " << std::to_string(linjaNro) << " viimeiset 5 leimausta:\n";
	for (int i = 0; i < leimaukset.size(); i++)
		cout << leimaukset[i];//.getLeimaajaNimi() << " : " << leimaukset[i].getLeimausAika();
	cout << '\n';
}


Leimaaja::~Leimaaja()
{
}