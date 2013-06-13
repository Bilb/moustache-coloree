/*
 * ColorClass.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef COLORCLASS_H_
#define COLORCLASS_H_

#include "Etage.h"
#include "../include/Contrainte.h"

#include <iostream>


using namespace std;

/**
 * Cette classe permet de rassembler les contraintes d'une même colorClass
 */
class ColorClass {
private:
	/**
	 * Le tableau des contraintes
	 */
	Contrainte* contraintes;
	/**
	 * Le nombre de sommets
	 */
	unsigned int nbSommet;

public:
	/**
	 * Construit et alloue l'espace nécessaire pour stocker nbSommet contraintes
	 */
	ColorClass(unsigned int nbSommet);

	/**
	 * Constructeur magique qui copie une autre colorClass en remplaçant le sommet search par le replace. Il fait tout cela
	 * sous les conditions de l'algorithme : voir le rapport pour des détails
	 */
	ColorClass(map<unsigned int, unsigned int> &rowToSommet, map<unsigned int, unsigned int> &sommetToRow,
			unsigned int nbSommet, ColorClass& src, unsigned int search, unsigned int replace);



	friend ostream& operator<<(ostream& out , const ColorClass& colorClass );


	Contrainte* getContraintes() { return contraintes;}
	virtual ~ColorClass();
};

#endif /* COLORCLASS_H_ */
