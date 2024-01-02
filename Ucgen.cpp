#include <iostream>
#include "Ucgen.h"
#include "DogruParcasi.h"

Ucgen::Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3){
	setNokta1(nokta1);
	setNokta2(nokta2);
	setNokta3(nokta3);
}

void Ucgen::setNokta1(const Nokta& nokta) {
	nokta1 = nokta;
}

void Ucgen::setNokta2(const Nokta& nokta) {
	nokta2 = nokta;
}

void Ucgen::setNokta3(const Nokta& nokta) {
	nokta3 = nokta;
}


Nokta Ucgen::getNokta1() const {
	return nokta1;
}

Nokta Ucgen::getNokta2() const {
	return nokta2;
}

Nokta Ucgen::getNokta3() const {
	return nokta3;
}


std::string Ucgen::toString() const {
	return "Ucgen: " + nokta1.toString() + " " + nokta2.toString() + " " + nokta3.toString();
}

double Ucgen::alan() const {
	//Alan = 1/2 x |(x1y2 + x2y3 + x3y1) - (x2y1 + x3y2 + x1y3)|
	double alan = (0.5) * std::abs(((nokta1.getX() * nokta2.getY()) + (nokta2.getX() * nokta3.getY()) + (nokta3.getX() * nokta1.getY())) - ((nokta2.getX() * nokta1.getY()) + (nokta3.getX() * nokta2.getY()) + (nokta1.getX() * nokta3.getY())));
	return alan;
}

double Ucgen::cevre() const {
	Nokta A(nokta1);
	Nokta B(nokta2);
	Nokta C(nokta3);

	DogruParcasi dogru1(A, B);
	DogruParcasi dogru2(A, C);
	DogruParcasi dogru3(B, C);

	double cevre = dogru1.uzunluk() + dogru2.uzunluk() + dogru3.uzunluk();
	return cevre;
}


double* Ucgen::acilar() const {
	// α = arccos((b^2 + c^2 - a^2) / (2 . b . c))
	// β = arccos((a^2 + c^2 - b^2) / (2 . a . c))
	// γ = arccos((a^2 + b^2 - c^2) / (2 . a . b))

	const double PI = 3.14;

	Nokta A(nokta1);
	Nokta B(nokta2);
	Nokta C(nokta3);

	DogruParcasi kenar1(A, B);
	DogruParcasi kenar2(A, C);
	DogruParcasi kenar3(B, C);

	double a = kenar1.uzunluk();
	double b = kenar2.uzunluk();
	double c = kenar3.uzunluk();

	double* acilar = new double[3];

	acilar[0] = std::acos((b * b + c * c - a * a) / (2 * b * c)) * (180 / PI);
	acilar[1] = std::acos((a * a + c * c - b * b) / (2 * a * c)) * (180 / PI);
	acilar[2] = std::acos((a * a + b * b - c * c) / (2 * a * b)) * (180 / PI);

	return acilar;
}