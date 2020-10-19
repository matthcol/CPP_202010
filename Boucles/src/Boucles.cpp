//============================================================================
// Name        : Boucles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

/**
 * first : iterator sur le 1er element parcouru (inclus)
 * last : iterator sur le dernier element du parcours (exclus)
 */
void displayVectorPair(
		vector<pair<double, double>>::const_iterator first,
		vector<pair<double, double>>::const_iterator last)
{
	for (; first != last; ++first) {
		cout << '<' << first->first << ", " << first->second << "> ; ";
	}
	cout << endl;
}

int main() {
	double temperatures[] = { 12.2, 3.4, 4.5 };
	vector<double> pressions = { 1024.3, 1030.2, 1017.1 };
	vector<pair<double,double>> data = {{12.2, 1024.4}, {14.1, 1030.5}};
	// boucle à l'ancienne
	for (size_t i=0; i<pressions.size(); i++) {
		cout << pressions[i] << ' ';
	}
	cout << endl;
	// boucle avec iterateur explicite (better ++it que it++)
	for (vector<double>::iterator it = pressions.begin(); it != pressions.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	for (double *it=begin(temperatures); it != end(temperatures); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	// foreach utilise les itérateurs de manière implicite
	for (double pression: pressions) {
		cout << pression << ' ';
	}
	cout << endl;
	for (double temperature: temperatures) {
			cout << temperature << ' ';
	}
	cout << endl;
	// parcours sur un conteneur d'objets : privilégier le mode référence
	for (const pair<double, double> &d: data) {
		cout << d.first << ", " << d.second << " -  ";
		//d.first = 0.0;
	}
	cout << endl;
	for (pair<double, double> const &d: data) {
		cout << d.first << ", " << d.second << " -  ";
		// d.first = 0.0;
	}
	cout << endl;
	//NB: double * const * const p;
	for (pair<double, double> &d: data) {
		d.first = 0.0;
		cout << d.first << ", " << d.second << " -  ";
	}
	cout << endl;
	for (auto const &d: data) {
		cout << d.first << ", " << d.second << " -  ";
		// d.first = 0.0;
	}
	cout << endl;
	// iterateur sur data
	vector<pair<double,double>>::iterator it = data.begin();
	auto it_rw = data.begin(); // iterator en lecture/ecriture
	auto it_ro = data.cbegin(); // const_iterator en lecture seule
	auto it_rev_rw = data.rbegin(); // reverse_iterator
	auto it_rev_ro = data.crbegin(); // const_reverse_iterator
	const vector<pair<double,double>> &data2 = data;
	auto it_ro2 = data2.begin(); // const_iterator car le vector est const (privilégier cbegin)
	// passer des iterateurs en parametres d'algo
	displayVectorPair(data.begin(), data.end());
	displayVectorPair(data.cbegin(), data.cend());
	// displayVectorPair(data.rbegin(), data.rend()); // reverse_iterator n'est pas un iterator
	for (auto it=data.rbegin(); it != data.rend(); ++it) {
		cout << it->first << ", " << it->second << " -  ";
	}
	cout << endl;
	return 0;
}










