#include "Leimaaja.h"
#pragma warning(disable : 4996)

Leimaaja::Leimaaja()
{
	cout << "Syötä linjan numero: ";
	linjaNro = getIntFromStream();
	leimaajaNimet = std::deque<string>();
}

void Leimaaja::leimaa(Matkakortti& kortti, Matkatyyppi matkatyyppi) {
	if (kortti.matkusta(matkatyyppi)) {
		leimaajaNimet.push_front(kortti.palautaNimi());

		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
		auto str = oss.str();
		leimausAjat.push_front(str);

		if (leimaajaNimet.size() > 5) {
			leimaajaNimet.pop_back();
		}
		if (leimausAjat.size() > 5) {
			leimausAjat.pop_back();
		}
	}
}

Leimaaja &Leimaaja::operator<<(Matkakortti& kortti) {
	leimaa(kortti, HELSINKI);
	return *this;
}

void Leimaaja::tulostaLeimaukset() {
	cout << "Linjan " << std::to_string(linjaNro) << " viimeiset " << leimausAjat.size() << " leimausta:\n";
	for (int i = 0; i < leimaajaNimet.size(); i++) {
		cout << leimaajaNimet[i] << " : " << leimausAjat[i] << "\n";
	}
	cout << '\n';
}


Leimaaja::~Leimaaja()
{
}


