#ifndef NOKTA_H
#define NOKTA_H
#include <string>

class Nokta {
public:
	//Yapici fonksiyonlar
	Nokta();
	Nokta(double a);
	Nokta(double x, double y);
	Nokta(const Nokta& kopyaNokta);
	Nokta(Nokta& baskaNokta, double offset_x, double offset_y);

	//Setter fonksiyonlar
	void setX(double x);
	void setY(double y);
	void set(double x, double y);

	//Getter fonksiyonlar
	double getX() const;
	double getY() const;

	std::string toString() const;
	void yazdir() const;

private:
	double noktaX;
	double noktaY;
};

#endif