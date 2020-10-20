/*
 * Polygon.h
 *
 *  Created on: 20 oct. 2020
 *      Author: Matthias
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Point.h"
#include "Form.h"
#include <string>
#include <iostream>

class Polygon: public Form {
public:
	template<class PointIterator>
	Polygon(const std::string &name, PointIterator first, PointIterator last):Form(name) {
		size = std::distance(first, last);
		sommets = new Point[size];
		for (auto it = sommets; first != last; ++first, ++it) {
			*it = *first;
		}
	}

	Polygon(const Polygon &other) = default; // TODO: deep copy de sommets
	Polygon(Polygon &&other) = default;		// TODO: move de sommets et reset sommets/size other

	virtual void translate(double deltaX, double deltaY);

private:
	size_t size;
	Point *sommets;
};

std::ostream &operator<<(std::ostream &out, const Polygon& polygon);

#endif /* POLYGON_H_ */
