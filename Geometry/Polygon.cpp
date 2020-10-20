/*
 * Polygon.cpp
 *
 *  Created on: 20 oct. 2020
 *      Author: Matthias
 */

#include "Polygon.h"
#include <algorithm>
#include <functional>

void Polygon::translate(double deltaX, double deltaY) {
	std::for_each(sommets, sommets+size, [deltaX,deltaY](auto& summit){summit.translate(deltaX, deltaY);});
}

std::ostream& operator <<(std::ostream &out, const Polygon &polygon) {
	out << '[';
	if (polygon.getSize()>0) {
		out << polygon.at(0);
		for (size_t i=1; i<polygon.getSize(); i++){
			out << ',' << polygon.at(i);
		}
	}
	out << ']';
	return out;
}

size_t Polygon::getSize() const {
	return size;
}

const Point& Polygon::at(size_t pos) const{
	return sommets[pos];
}
