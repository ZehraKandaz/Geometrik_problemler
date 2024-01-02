#include <iostream>
#include "Daire.h"

Daire::Daire(const Nokta& merkezNokta, double yaricap) {
	setMerkez(merkezNokta);
	setYaricap(yaricap);
}

Daire::Daire(const Daire& kopyaDaire) {
	setMerkez(kopyaDaire.merkezNokta);
	setYaricap(kopyaDaire.yaricap);
}

Daire::Daire(const Daire& baskaDaire, double x) {
	setMerkez(baskaDaire.merkezNokta);
	setYaricap(baskaDaire.yaricap * x);
}


void Daire::setYaricap(double a) {
	yaricap = a;
}

void Daire::setMerkez(const Nokta& merkez) {
	merkezNokta = merkez;
}


double Daire::getYaricap() const {
	return yaricap;
}

Nokta Daire::getMerkez() const {
	return merkezNokta;
}


double Daire::alan() const {
	//Alan = π . r^2
	const double PI = 3.14;
	double alan = PI * yaricap * yaricap;
	return alan;
}

double Daire::cevre() const {
	//Cevre = 2 . π . r
	const double PI = 3.14;
	double cevre = 2 * PI * yaricap;
	return cevre;
}

double Daire::kesisim(const Daire& daire) const {
	double merkezUzaklik = std::sqrt(std::pow(merkezNokta.getX() - daire.merkezNokta.getX(), 2) + std::pow(merkezNokta.getY() - daire.merkezNokta.getY(), 2));
	double yaricapToplam = yaricap + daire.yaricap;

	if (merkezUzaklik < yaricapToplam) {
		if (merkezNokta.getX() == daire.merkezNokta.getX() && merkezNokta.getY() == daire.merkezNokta.getY() && yaricap == daire.yaricap) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 2;
	}

}

std::string Daire::toString() const{
	return "Merkez Noktasi: " + merkezNokta.toString() + "\nYaricap: " + std::to_string(yaricap).substr(0, std::to_string(yaricap).find(',') + 2);
}

void Daire::yazdir() const {
	std::cout << toString() << std::endl;
}