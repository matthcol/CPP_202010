/*
 * main.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */
#include "Form.h"
#include "Point.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	Form f("A"); // appel au constructeur
	Form *pf = new Form("B"); // alloue (new) puis initialise (appel constructeur)
	Form default_f;
	Point ptC("C",3.4, 4.5);
	cout << "#" << f.getName() << "#"
			<< pf->getName() << "#"
			<< default_f.getName() << "#"
			<< ptC.getName() << "/" << ptC.getX()
			<< endl;

	delete pf; // appel destructeur Form pf
	return 0;
} // appel le destructeur Form de f


