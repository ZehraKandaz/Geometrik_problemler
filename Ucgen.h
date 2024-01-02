#ifndef UCGEN_H
#define UCGEN_H
#include "Nokta.h"

class Ucgen {
public:
	//Yapici Fonksiyon
	Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3);

	//Setter Fonksiyonlar
	void setNokta1(const Nokta& nokta);
	void setNokta2(const Nokta& nokta);
	void setNokta3(const Nokta& nokta);

	//Getter Fonksiyonlar
	Nokta getNokta1() const;
	Nokta getNokta2() const;
	Nokta getNokta3() const;

	double alan() const;
	double cevre() const;
	std::string toString() const;
	double* acilar() const;

private:
	Nokta nokta1;
	Nokta nokta2;
	Nokta nokta3;
};

#endif