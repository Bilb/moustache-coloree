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
#include <map>

using namespace std;

class Contrainte {
private:
	Etage* etage1;
	Etage* etage2;
	unsigned int egalite;
	unsigned int nbSommet;
public:
	Contrainte();
	Contrainte(unsigned int nbSommet);



	Etage* getEtage1();
	Etage* getEtage2();
	void setEtage1(Etage* etage) { etage1 = etage; };
	void setEtage2(Etage* etage) { etage2 = etage; };

	unsigned int getNbSommet() const { return nbSommet; }


	void setByMagic(map<unsigned int, unsigned int> &rowToSommet,map<unsigned int, unsigned int> &sommetToRow,
			unsigned int nbSommet, unsigned int i, Contrainte& src, unsigned int search, unsigned int replace);


	/**
	 * resize etage1 and etage2 to a capacity of nbSommet
	 */
	void setNbSommet(unsigned int nbSommet);

	/**
	 * set etage1 & 2 with specific etages.
	 */
	void setNbSommet(unsigned int nbSommet, Etage* etage1_, Etage* etage2_);

	friend ostream& operator<<(ostream& out , Contrainte& cont );
	virtual ~Contrainte();
};

#endif /* CONTRAINTE_H_ */
