#include <iostream>
#include <sstream>
#include "Nokta.h"

Nokta::Nokta() {
	setX(0);
	setY(0);
}

Nokta::Nokta(double a) {
	setX(a);
	setY(a);
}

Nokta::Nokta(double x, double y) {
	setX(x);
	setY(y);
}

Nokta::Nokta(const Nokta& kopyaNokta) {
	setX(kopyaNokta.getX());
	setY(kopyaNokta.getY());
}

Nokta::Nokta(Nokta& baskaNokta, double offset_x, double offset_y) {
	setX(baskaNokta.getX() + offset_x);
	setY(baskaNokta.getY() + offset_y);
}


void Nokta::setX(double x) {
	noktaX = x;
}

void Nokta::setY(double y) {
	noktaY = y;
}

void Nokta::set(double x, double y) {
	setX(x);
	setY(y);
}


double Nokta::getX() const {
	return noktaX;
}

double Nokta::getY() const {
	return noktaY;
}


std::string Nokta::toString() const {
	std::stringstream ss;
	ss << "(" << getX() << ", " << getY() << ")";
	return ss.str();
}

void Nokta::yazdir() const {
	std::cout << toString() << std::endl;
}