/*
 * Point.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#include "Point.h"

//Point::Point(): Form(), x(0.0), y(0.0){}
Point::Point(): Point("",0.0, 0.0){}


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

std::ostream &operator<<(std::ostream &out, const Point &pt) {
	return out << pt.getName() << '(' << pt.getX() << ',' << pt.getY() << ')';
}

