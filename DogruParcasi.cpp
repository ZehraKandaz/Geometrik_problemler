#include <iostream>
#include "DogruParcasi.h"

DogruParcasi::DogruParcasi(const Nokta& nokta1, const Nokta& nokta2) {
    setBaslangicNoktasi(nokta1);
    setBitisNoktasi(nokta2);
}

DogruParcasi::DogruParcasi(const DogruParcasi& kopyaDogru) {
    setBaslangicNoktasi(kopyaDogru.baslangicNoktasi);
    setBitisNoktasi(kopyaDogru.bitisNoktasi);
}

DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    //P1(x1,y1) = (x0 - (L / (2 . √1 + m^2), y0 - (m.L / (2 . √1 + m^2))
    //P2(x2,y2) = (x0 + (L / (2 . √1 + m^2), y0 + (m.L / (2 . √1 + m^2))
    double x0 = ortaNokta.getX();
    double y0 = ortaNokta.getY();
    
    double x1 = x0 - (uzunluk / (2 * sqrt(1 + egim * egim)));
    double y1 = y0 - (egim * uzunluk / (2 * sqrt(1 + egim * egim)));

    double x2 = x0 + (uzunluk / (2 * sqrt(1 + egim * egim)));
    double y2 = y0 + (egim * uzunluk / (2 * sqrt(1 + egim * egim)));

    Nokta baslangic(x1, y1);
    Nokta bitis(x2, y2);
    setBaslangicNoktasi(baslangic);
    setBitisNoktasi(bitis);
}


void DogruParcasi::setBaslangicNoktasi(const Nokta& baslangic) {
    baslangicNoktasi = baslangic;
}

void DogruParcasi::setBitisNoktasi(const Nokta& bitis) {
    bitisNoktasi = bitis;
}


Nokta DogruParcasi::getBaslangicNoktasi() const {
    return baslangicNoktasi;
}

Nokta DogruParcasi::getBitisNoktasi() const {
    return bitisNoktasi;
}


double DogruParcasi::uzunluk() const {
	// |AB| = √((x2 - x1)^2 + (y2 - y1)^2)
	double uzunluk = std::sqrt(std::pow(bitisNoktasi.getX() - baslangicNoktasi.getX(), 2) + std::pow(bitisNoktasi.getY() - baslangicNoktasi.getY(), 2));
	return uzunluk;
}

Nokta DogruParcasi::kesisim(const Nokta& nokta) const {
    double x1 = baslangicNoktasi.getX();
    double y1 = baslangicNoktasi.getY();

    double x2 = bitisNoktasi.getX();
    double y2 = bitisNoktasi.getY();

    double x3 = nokta.getX();
    double y3 = nokta.getY();

    // Doğru parçasının eğimi
    double egim = (y2 - y1) / (x2 - x1);

    // Dik olan doğrunun eğimi
    double dikEgim = -1.0 / egim;

    // İki denklemin kesisim noktasını bulma
	//Dik dogrunun denklemi : y - y3 = dikEgim * (x - x3)
	//Dogru parcasinin denklemi y - y1 = m * (x - x1)
	// Bu iki denklem ortak olarak çözülür ve kesisim noktasi bulunur.
    double kesimX = (dikEgim * x3 - egim * x1 + y1 - y3) / (dikEgim - egim);
    double kesimY = dikEgim * (kesimX - x3) + y3;

    Nokta n(kesimX, kesimY);
    return n;
}

Nokta DogruParcasi::ortaNokta() const {
	// x0 = (x1 + x2) / 2
	// y0 = (y1 + y2) / 2
	double x0 = (baslangicNoktasi.getX() + bitisNoktasi.getX()) / 2.0;
	double y0 = (baslangicNoktasi.getY() + bitisNoktasi.getY()) / 2.0;
	Nokta ortaNokta(x0, y0);
	return ortaNokta;
}

std::string DogruParcasi::toString() const {
	return "Baslangic Noktasi: " + baslangicNoktasi.toString() + "\nBitis Noktasi: " + bitisNoktasi.toString();
}

void DogruParcasi::yazdir() const {
	std::cout << toString() << std::endl;
}