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
	out << polygon.getName() << '[';
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

Polygon::Polygon(const Polygon &other): Form(other), size(other.size) {
	this->sommets = new Point[other.size];
	for (size_t i=0; i < other.size ; i++) {
		this->sommets[i] = other.sommets[i];
	}
}

Polygon::Polygon(Polygon &&other): Form(std::move(other)), size(other.size), sommets(other.sommets) {
	other.size=0;
	other.sommets = nullptr;
}

const Point& Polygon::at(size_t pos) const{
	return sommets[pos];
}
