/*
 * Form.h
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#ifndef FORM_H_
#define FORM_H_

#include <string>

class Form {
public:
	Form() = default;
	Form(const std::string &name);
	const std::string& getName() const;
	void setName(const std::string &name);
	virtual void translate(double deltaX, double deltaY)=0;

//	virtual ~Form();
private:
	std::string name; // appel le constructeur défaut de string
};

#endif /* FORM_H_ */
