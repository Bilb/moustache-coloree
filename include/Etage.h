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



class Etage {
private:
	unsigned int nbSommet;

	boost::dynamic_bitset<> bitsetColor;
	SimpleLinkList<unsigned int> listColor;

public:
	Etage(unsigned int nbSommet_);

	SimpleLinkList<unsigned int> getListColor() const { return listColor;}

	void setListColor(SimpleLinkList<unsigned int> list) const { listColor = list;}


	/**
	 * Met à true l'indice correspondant au sommet indice -1
	 * Note : on commence les indices à 0!
	 */
	void set(unsigned int indice);

	/**
	 * test si le sommet (indice -1) est à true ou non.
	 */
	bool test(unsigned int indice);

	/**
	 * Met à false l'indice correspondant au sommet (indice -1)
	 * Note : on commence les indices à 0!
	 */
	void reset(unsigned int indice);



	friend std::ostream& operator<<(std::ostream& out , const Etage& etage );


	virtual ~Etage();
};

#endif /* ETAGE_H_ */
