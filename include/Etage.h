/*
 * Etage.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef ETAGE_H_
#define ETAGE_H_

#include <iostream>
#include <boost/dynamic_bitset.hpp>

#include "SimpleLinkList.h"

using namespace std;

class Etage {
private:
	unsigned int nbSommet;
	boost::dynamic_bitset<> bitsetColor;
	std::list<int> listColor;

public:
	Etage(unsigned int nbSommet);

	SimpleLinkList<int> getListColor() { return listColor;}
	boost::dynamic_bitset<> getBitsetColor() { return bitsetColor;}


	/**
	 * Met à true l'indice correspondant au sommet indice -1
	 * Note : on commence les indices à 0!
	 */
	void set(unsigned int indice);

	/**
	 * Met à false l'indice correspondant au sommet indice -1
	 * Note : on commence les indices à 0!
	 */
	void reset(unsigned int indice);

	friend ostream& operator<<(ostream& out , const Etage& etage );


	virtual ~Etage();
};

#endif /* ETAGE_H_ */
