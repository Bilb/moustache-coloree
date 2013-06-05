/*
 * Contrainte.cpp
 *
 *  Created on: 4 juin 2013
 *      Author: audric
 */

#include <iostream>

using namespace std;


#include "../include/Contrainte.h"
#include "../include/Etage.h"

Contrainte::Contrainte() {
	nbSommet = 0;
	etage1 = NULL;
	etage2 = NULL;
}

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




void Contrainte::setByMagic(unsigned int nbSommet_, unsigned int i, Contrainte& src, unsigned int search, unsigned int replace)
{
	nbSommet = src.getNbSommet();
	if(etage1)
		delete etage1;
	if(etage2)
		delete etage2;

	etage1 = new Etage(nbSommet);
	etage2 = new Etage(nbSommet);

	/* This is where magic happens */
	//todo
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

	/* This is where magic happens */
}



ostream& operator<<(ostream& out , const Contrainte& cont ) {
	out << "nbSommets: " << cont.getNbSommet() << endl;
	if(cont.getEtage1()!= NULL)
		out << "\tetage1: " << *cont.getEtage1() << endl;
	else
		out << "\tetage1: " << "NULL" << endl;

	if(cont.getEtage2()!= NULL)
		out << "\tetage2: " << *cont.getEtage2() << endl;
	else
		out << "\tetage2: " << "NULL" << endl;
	return out;
}

