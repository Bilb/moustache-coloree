/*
 * Etage.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include "../include/Etage.h"

#define NDEBUG
#include <assert.h>
#include <iostream>


Etage::Etage(unsigned int nbSommet_) : nbSommet(nbSommet_),
bitsetColor(nbSommet),
listColor()
{
}

Etage::~Etage() {
}


void Etage::set(unsigned int indice) {

	assert(indice < nbSommet);


	if(!bitsetColor[indice]) {
		bitsetColor.set(indice);
		listColor.pushBack(indice);
	}
}


bool Etage::test(unsigned int indice) {
	if(!bitsetColor[indice]) {
		return false;
	}
	return true;
}


void Etage::reset(unsigned int indice) {
	assert(indice < nbSommet);

	if(bitsetColor[indice]) {
		bitsetColor.reset(indice);
		listColor.removeAllOccurences(indice);
	}
}



void Etage::setFromList(SimpleLinkList<unsigned int> list) {
	Maillon<unsigned int>* current = list.begin();
	while(current != NULL) {
		set(current->getObject() - 1);
		current = current->getNext();
	}
}


ostream& operator<<(ostream& out , const Etage& etage ) {
	out << "nbSommets: " << etage.nbSommet << " values:" << etage.bitsetColor;
	return out;
}
