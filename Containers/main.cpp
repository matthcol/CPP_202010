/*
 * main.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#include <iostream>
#include <list>
#include <set>
#include <functional>

#include "display.h"

int main(int argc, char **argv) {
	// types linéaires : (coût d'accès/insert à 1 pos)
//			vector, array : O(1)
//			list (forward) : O(n)
//			set (unordered), O(log(n))
//			stack, deque, queue
	// autres conteneurs : map (unordered) : O(log(n))
	// 1. init statique avec {}
	// list: doubly linked list, efficient for insert/remove, not for random access
	std::list<std::pair<double, double>> data_list = {{1.0, 10.0}, {2.0, 20.0}, {3.0, 30.0}};
	// data_list.begin() + 1 forbidden (no random access: at/[])
	auto it = data_list.begin();
	++it;
	// data_list.insert(it, std::pair<double,double>(4.0, 40.0));
	data_list.insert(it, std::make_pair(4.0, 40.0));
	std::cout << data_list.front().first << std::endl;

	// 2. set (ordered) : unicité, rangé (opérateur <)
	std::set<std::pair<double, double>> data_set = {{1.0, 10.0}, {2.0, 20.0}, {3.0, 30.0}};
	data_set.insert(std::make_pair(2.0, 15.0));
	displayData(cbegin(data_set), cend(data_set));
	// reverse asc set in desc set :
	// std::set<std::pair<double, double>, std::greater<std::pair<double, double>>> data_set_desc;
	// data_set_desc.insert(data_set.cbegin(), data_set.cend());
	std::set<std::pair<double, double>, std::greater<std::pair<double, double>>> data_set_desc(
			data_set.cbegin(), data_set.cend());
	for (const auto &p: data_set_desc) {
		std::cout << p.first << ", " << p.second << " / ";
	}
	std::cout << std::endl;

	// test sur conteneur simple:
	std::set<double> pressions = {1024.3, 1030.0};
	displayData(begin(pressions), end(pressions));

	// 3. array de taille fixe : calcul numerique avec random access
	std::array<double,10> temperatures;
	temperatures.fill(25);
	displayData(begin(temperatures), end(temperatures));

}


