/*
 * Form.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#include "Form.h"

Form::Form(const std::string &name):name(name) // list initialization
{
}

const std::string& Form::getName() const {
	return name;
}

void Form::setName(const std::string &name) {
	this->name = name;
}
//Form::~Form() {
//	// TODO Auto-generated destructor stub
//}

