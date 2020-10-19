/*
 * display.h
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>

template<class InputIterator>
void displayData(InputIterator first, InputIterator last) {
	for (; first != last; ++first) {
		(std::cout << *first) << ", ";
	}
	std::cout << std::endl;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
	return out << '<' << p.first << ", " << p.second << '>';
}

#endif /* DISPLAY_H_ */
