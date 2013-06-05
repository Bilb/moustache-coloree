/*
 * Contrainte.h
 *
 *  Created on: 4 juin 2013
 *      Author: audric
 */

#ifndef CONTRAINTE_H_
#define CONTRAINTE_H_

#include "../include/Etage.h"

#include <iostream>


using namespace std;

class Contrainte {
private:
	Etage* etage1;
	Etage* etage2;
	unsigned int nbSommet;
public:
	Contrainte();
	Contrainte(unsigned int nbSommet);



	Etage* getEtage1() const { return etage1;}
	Etage* getEtage2() const { return etage2;}
	void setEtage1(Etage* etage) { etage1 = etage; };
	void setEtage2(Etage* etage) { etage2 = etage; };

	unsigned int getNbSommet() const { return nbSommet; }


	void setByMagic(unsigned int nbSommet, unsigned int i, Contrainte& src, unsigned int search, unsigned int replace);

	/**
	 * resize etage1 and etage2 to a capacity of nbSommet
	 */
	void setNbSommet(unsigned int nbSommet);

	friend ostream& operator<<(ostream& out , const Contrainte& cont );

	virtual ~Contrainte();
};

#endif /* CONTRAINTE_H_ */
