/*
 * Point.h
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#ifndef POINT_H_
#define POINT_H_

#include "Form.h"

class Point: public Form {
public:
	Point()=default;
	Point(const std::string &name, double x, double y);
	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

private:
	double x;
	double y;
};

#endif /* POINT_H_ */
