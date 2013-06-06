/*
 * ColorClass.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include "../include/ColorClass.h"


#include <iostream>

using namespace std;

ColorClass::ColorClass(unsigned int nbSommet_) : nbSommet(nbSommet_){
	if(nbSommet > 0) {
		contraintes = new Contrainte[nbSommet]();
		unsigned int indice;
		for(indice = 0; indice < nbSommet ; indice++) {
			contraintes[indice].setNbSommet(nbSommet);
		}
	}
	else {
		contraintes = NULL;
	}
}

ColorClass::~ColorClass() {
	delete[] contraintes;
}



ColorClass::ColorClass(map<unsigned int, unsigned int> &rowToSommet, map<unsigned int, unsigned int> &sommetToRow, unsigned int nbSommet_, ColorClass& src, unsigned int search, unsigned int replace)  :
						nbSommet(nbSommet_)
{
	contraintes = new Contrainte[nbSommet]();
	unsigned int indice;
	for(indice = 0; indice > nbSommet ; ++indice) {
		contraintes[indice].setByMagic(rowToSommet, sommetToRow, nbSommet,indice, src.contraintes[indice], search, replace);
	}
}


ostream& operator<<(ostream& out , const ColorClass& colorClass ) {
	out << "nbSommets: " << colorClass.nbSommet << endl;

	unsigned int indice;

	if(colorClass.nbSommet > 0) {
		for(indice = 0; indice < colorClass.nbSommet; indice++) {
			out << "\tcontrainte num"  << indice << ": "<< colorClass.contraintes[indice] <<endl;
		}
	}
	else {
		out << "NULL" << endl;
	}

	return out;
}
