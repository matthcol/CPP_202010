/*
 * Form.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#include "Form.h"
#include <iostream>

//Form::Form() {
//	std::cout << "Default form" << std::endl;
//}

Form::Form(const std::string &name):name(name) // list initialization
{
}

const std::string& Form::getName() const {
	return name;
}

//Form::Form(Form &&other):name(std::move(name)) {
//}

void Form::setName(const std::string &name) {
	this->name = name;
}

//void Form::translate(double deltaX, double deltaY) {
//}
