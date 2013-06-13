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



/**
 * Un étage est un ensemble de numéro de sommet
 */
class Etage {
private:
	/**
	 * Nombre de sommet de cet étage
	 */
	unsigned int nbSommet;

	/**
	 * dynamic_bitset permettant un acccès direct pour tester si un sommet est un interdit ou non
	 */
	boost::dynamic_bitset<> bitsetColor;

	/**
	 * Liste des sommets contenu dans cet étage
	 */
	SimpleLinkList<unsigned int> listColor;

public:
	/**
	 * Construit et alloue l'espace nécessaire pour stocker nbSommet sommet dans cet étage
	 */
	Etage(unsigned int nbSommet_);

	SimpleLinkList<unsigned int> getListColor() const { return listColor;}

	/**
	 * "Copie" la liste list dans cet étage.
	 */
	void setFromList(SimpleLinkList<unsigned int> list);


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
