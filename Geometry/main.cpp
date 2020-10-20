/*
 * main.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */
#include "Form.h"
#include "Point.h"
#include "Polygon.h"

#include <iostream>
#include <vector>
#include <optional>
#include <functional>

using namespace std;

optional<string> nameFromForm(const Form& form) {
	if (form.getName().empty()) {
			return {};
	} else {
		return form.getName();
	}
}

void testPointsForms() {
//	Form f("A"); // appel au constructeur
//	Form *pf = new Form("B"); // alloue (new) puis initialise (appel constructeur)
//	Form default_f;
	Point ptC("C",3.4, 4.5);
	Point default_pt;
//	Point copy_pt(ptC); // error if deleted constructor by copy
//	cout << "#" << f.getName() << "#"
//			<< pf->getName() << "#"
//			<< default_f.getName() << "#" << endl;
	cout << ptC
	//		<< " # " << copy_pt
			<< endl;
	ptC.translate(3.0, 4.0);
	cout << "after Point translate: " << ptC << endl;
	Form &f = ptC;
	f.translate(2.0, 5.0);
	cout << "after Form translate: " << ptC << endl;
//	delete pf; // appel destructeur Form pf
	cout << nameFromForm(ptC).value_or("empty") << " / " << nameFromForm(default_pt).value_or("empty") << endl;

	Point *ppt = nullptr;

	//vector<Point> points {ptC, default_pt};
	vector<Point> points; //  {Point("D", 3.4, 4.5), Point("E", 4.6, 5.9)};  // error use copy constructor
	points.push_back(Point("D", 3.4, 4.5));  // Point en rvalue
	points.push_back(Point("E", 5.4, 7.5));  // Point en rvalue
	points.push_back(std::move(ptC));  // Point ptC en lvalue transformed en rvalue
	vector<double> res(points.size());
	cout << "Point C after move:" << ptC << endl;

	transform(cbegin(points), cend(points), begin(res), [](const auto &o){return o.getX();});
	cout << res[0] << '#' << res[2] << endl;

	transform(cbegin(points), cend(points), begin(res), std::mem_fn(&Point::getX));  // getX sur const Point&
	cout << res[0] << '@' << res[2] << endl;

	vector<Point *> points_ptr {&ptC, &default_pt};
	transform(cbegin(points_ptr), cend(points_ptr), begin(res), std::mem_fn(&Point::getX)); // getX sur const Point*
	cout << res[0] << ':' << res[2] << endl;

	string s("Happy");
	string s2(std::move(s));
	cout << s << '/' << s2 << endl;

	Point point_move(Point("H",1.0,2.0)); // constructor par move sur rvalue
	Point point_move2;
	point_move2 = Point("I",1.0,2.0); // operator d'affectation par move sur rvalue
}

void testPolygon() {
	vector<Point> source;
	source.push_back(Point());
	source.push_back(Point("A", 3, 0));
	source.push_back(Point("B", 0, 4));
	Polygon poly("P", begin(source), end(source));
	// 1. print poly
	cout << "Init:" << poly << endl;
	// 2. copy poly
	Polygon poly2(poly); // copy
	poly.translate(1.0, 1.0);
	cout << "After copy:" << poly << endl; // check: poly unchanged
	cout << "After copy:" << poly2 << endl;
	// 3. move poly
	Polygon poly3(std::move(poly)); // move
	poly.translate(1.0, 1.0);
	cout << "After move:" << poly << endl;  // check: empty poly
	cout << "After copy:" << poly3 << endl;
}

int main(int argc, char **argv) {
	testPolygon();
	return 0;
}


