/*
 * main.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */
#include "Form.h"
#include "Point.h"
#include <iostream>
#include <optional>

using namespace std;

optional<string> nameFromForm(const Form& form) {
	if (form.getName().empty()) {
			return {};
	} else {
		return form.getName();
	}
}

int main(int argc, char **argv) {
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
	return 0;
} // appel le destructeur Form de f


