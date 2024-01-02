#ifndef DOGRUPARCASI_H
#define DOGRUPARCASI_H

#include "Nokta.h"

class DogruParcasi {
public:
	//Yapici Fonksiyonlar
	DogruParcasi(const Nokta& nokta1, const Nokta& nokta2);
	DogruParcasi(const DogruParcasi& kopyaDogru);
	DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);

	//Setter Fonksiyonlar
	void setBaslangicNoktasi(const Nokta& baslangic);
	void setBitisNoktasi(const Nokta& bitis);

	//Getter Fonksiyonlar
	Nokta getBaslangicNoktasi() const;
	Nokta getBitisNoktasi() const;

	double uzunluk() const;
	Nokta kesisim(const Nokta& nokta) const;
	Nokta ortaNokta() const;
	std::string toString() const;
	void yazdir() const;

private:
	Nokta baslangicNoktasi;
	Nokta bitisNoktasi;
};

#endif