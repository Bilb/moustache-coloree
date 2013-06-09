/*
 * Etage.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include "../include/Etage.h"

#include <assert.h>
#include <iostream>


Etage::Etage(unsigned int nbSommet_) : nbSommet(nbSommet_),
bitsetColor(nbSommet),
listColor()
{
}

Etage::~Etage() {
	// TODO Auto-generated destructor stub
}


void Etage::set(unsigned int indice) {

	//cout << "trying to set indice: "<< indice << endl;
	assert(indice < nbSommet);


	//cout << bitsetColor << endl;
	if(!bitsetColor[indice]) {
		//	cout << "not already set" << endl;
		bitsetColor.set(indice);
		listColor.pushBack(indice);
	}
	//cout << "sortie set" << endl;
}




void Etage::reset(unsigned int indice) {
	//cout << "entree reset" << endl;
	assert(indice < nbSommet);

	if(bitsetColor[indice]) {
		bitsetColor.reset(indice);
		listColor.removeAllOccurences(indice);
	}

	//	cout << "sortie reset" << endl;

}


ostream& operator<<(ostream& out , const Etage& etage ) {
	out << "nbSommets: " << etage.nbSommet << " values:" << etage.bitsetColor;
	//etage.getListColor().print();
	return out;
}
