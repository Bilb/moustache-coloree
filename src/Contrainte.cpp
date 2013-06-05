/*
 * Contrainte.cpp
 *
 *  Created on: 4 juin 2013
 *      Author: audric
 */

#include <iostream>
#include <stdio.h>

using namespace std;


#include "../include/Contrainte.h"
#include "../include/Etage.h"

Contrainte::Contrainte(unsigned int nbSommet_) : nbSommet(nbSommet_) {
	if(nbSommet > 0) {
		etage1 = new Etage(nbSommet);
		etage2 = new Etage(nbSommet);
	}
	else {
		etage1 = NULL;
		etage2 = NULL;
	}
}

Contrainte::~Contrainte() {
	delete etage1;
	delete etage2;
}




void Contrainte::setByMagic(map<unsigned int, unsigned int> &rowToSommet, map<unsigned int, unsigned int> &sommetToRow,
		unsigned int nbSommet_, unsigned int indice, Contrainte& src, unsigned int search, unsigned int replace)
{
	nbSommet = nbSommet_;
	if(etage1)
		delete etage1;
	if(etage2)
		delete etage2;

	etage1 = new Etage(nbSommet);
	etage2 = new Etage(nbSommet);

	/* This is where magic happens */
	//todo
	unsigned int rowSearch = sommetToRow[search];

	if(indice == rowSearch) {
		//cas d'égalité : mettre une égalité. todo
	}
	else if( indice > rowSearch) {
		// faire le search & replace :
		/* etage1 */
		// parcourir la liste de etage1, si égale à search, faire un set(replace) (et mettre un bool à true), sinon faire un set de celui trouvé dans la liste

		/* etage2 */
		// parcourir la liste de etage2, si on tombe sur search, alors si bool=true, ne rien faire, il est déjà dans l'étage1
		// 		sinon si bool = false, faire un etage2.set(replace)
		// sinon, ajouter celui trouver dans l'etage2
	}
	else {
		// copier simplement les deux étages de la src, on a un  rang inférieur au replace : rien à faire de plus
		// parcourir la liste de src.etage1 et faire un set de etage1
		// parcourir la liste de src.etage2 et faire un set de etage2
	}





}



void Contrainte::setNbSommet(unsigned int nbSommet_)
{
	nbSommet = nbSommet_;
	if(etage1)
		delete etage1;
	if(etage2)
		delete etage2;

	etage1 = new Etage(nbSommet);
	etage2 = new Etage(nbSommet);
}


void Contrainte::setNbSommet(unsigned int nbSommet_, Etage* etage1_, Etage* etage2_)
{
	nbSommet = nbSommet_;
	if(etage1)
		delete etage1;
	if(etage2)
		delete etage2;

	etage1 = etage1_;
	etage2 = etage2_;
}


ostream& operator<<(ostream& out , const Contrainte& cont ) {
	out << "\tnbSommets: " << cont.getNbSommet() << endl;
	if(cont.getEtage1()!= NULL)
		out << "\t\tetage1: " << *cont.getEtage1() << endl;
	else
		out << "\t\tetage1: " << "NULL" << endl;

	if(cont.getEtage2()!= NULL)
		out << "\t\tetage2: " << *cont.getEtage2() << endl;
	else
		out << "\t\tetage2: " << "NULL" << endl;
	return out;
}

