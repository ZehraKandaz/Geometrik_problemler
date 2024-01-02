#ifndef DAIRE_H
#define DAIRE_H
#include "Nokta.h"

class Daire {
public:
	//Yapici Fonksiyonlar
	Daire(const Nokta& merkezNokta, double yaricap);
	Daire(const Daire& kopyaDaire);
	Daire(const Daire& baskaDaire, double x);

	//Setter Fonksiyonlar
	void setYaricap(double a);
	void setMerkez(const Nokta& merkez);

	//Getter Fonksiyonlar
	double getYaricap() const;
	Nokta getMerkez() const;

	double alan() const;
	double cevre() const;
	double kesisim(const Daire& daire) const;
	std::string toString() const;
	void yazdir() const;

private:
	double yaricap;
	Nokta merkezNokta;
};

#endif