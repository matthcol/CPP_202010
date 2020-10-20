/*
 * Polygon.cpp
 *
 *  Created on: 20 oct. 2020
 *      Author: Matthias
 */

#include "Polygon.h"

void Polygon::translate(double deltaX, double deltaY) {
	// TODO: (later)
	return out;
}

std::ostream& operator <<(std::ostream &out, const Polygon &polygon) {

}

size_t Polygon::getSize() const {
	return size;
}

const Point& Polygon::at(size_t pos) const{
	return sommets[pos];
}
