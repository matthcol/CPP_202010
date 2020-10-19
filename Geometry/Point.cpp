/*
 * Point.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#include "Point.h"

Point::Point(const std::string &name, double x, double y): Form(name), x(x), y(y)
{
}

double Point::getX() const {
	return x;
}

void Point::setX(double x) {
	this->x = x;
}

double Point::getY() const {
	return y;
}

void Point::setY(double y) {
	this->y = y;
}
