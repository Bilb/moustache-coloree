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

/**
 * Cette classe rassemble les deux étages ainsi que la possible égalité d'une contrainte
 * Une contrainte est par exemple : [1] [2,3]
 */
class Contrainte {
private:
	/**
	 * l'etage 1 de cette contrainte
	 */
	Etage* etage1;

	/**
	 * l'etage 2 de cette contrainte
	 */
	Etage* etage2;
	/**
	 * Le sommet auquel cette contrainte est égale. Par défault : -1 (i.e. plus de 4 000 000 comme c'est un unsigned)
	 */
	unsigned int egalite;

	/**
	 * Nombre de sommet de ce problème
	 */
	unsigned int nbSommet;
public:
	/**
	 * Construit une contraite en allouant pas d'espace supplémentaire. Un appel à
	 * setNbSommet ou setByMagic est nécessaire
	 */
	Contrainte();

	/**
	 * Construit une contraite en allouant l'espace nécessaire au stockage  de nbSommet
	 */
	Contrainte(unsigned int nbSommet);



	Etage* getEtage1();
	Etage* getEtage2();
	void setEtage1(Etage* etage) { etage1 = etage; };
	void setEtage2(Etage* etage) { etage2 = etage; };

	unsigned int getNbSommet() const { return nbSommet; }

	/**
	 * Constructeur magic construisant une contrainte à partir d'une autre, tout en remplaçant les sommets qu'il faut.
	 * voir le rapport pour plus de détail
	 */
	void setByMagic(map<unsigned int, unsigned int> &rowToSommet,map<unsigned int, unsigned int> &sommetToRow,
			unsigned int nbSommet, unsigned int i, Contrainte& src, unsigned int search, unsigned int replace);


	/**
	 * resize etage1 and etage2 to a capacity of nbSommet
	 */
	void setNbSommet(unsigned int nbSommet);

	/**
	 * set etage1 & 2 with specific etages.
	 */
	void setParams(unsigned int nbSommet, Etage* etage1_, Etage* etage2_);

	friend ostream& operator<<(ostream& out , Contrainte& cont );
	virtual ~Contrainte();
};

#endif /* CONTRAINTE_H_ */
