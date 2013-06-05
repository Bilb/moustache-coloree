/*
 * Etage.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include "../include/Etage.h"

#include <assert.h>
#include <iostream>

using namespace std;

Etage::Etage(unsigned int nbSommet_) : nbSommet(nbSommet_),
bitsetColor(nbSommet),
listColor()
{
}

Etage::~Etage() {
	// TODO Auto-generated destructor stub
}


void Etage::set(unsigned int indice) {
	assert(indice < nbSommet);

	if(!bitsetColor[indice]) {
		bitsetColor.set(indice);
		listColor.push_back(indice);
	}
}




void Etage::reset(unsigned int indice) {
	assert(indice < nbSommet);

	if(bitsetColor[indice]) {
		bitsetColor.reset(indice);
		listColor.remove(indice);
	}

}


ostream& operator<<(ostream& out , const Etage& etage ) {
	out << "nbSommets: " << etage.nbSommet << " values:" << etage.bitsetColor;
	return out;
}
