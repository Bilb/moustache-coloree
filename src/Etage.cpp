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
	//listColor = list;
	Maillon<unsigned int>* current = list.begin();
	while(current != NULL) {
		set(current->getObject() - 1);
		current = current->getNext();
	}
}


ostream& operator<<(ostream& out , const Etage& etage ) {
	out << "nbSommets: " << etage.nbSommet << " values:" << etage.bitsetColor;
	//etage.getListColor().print();
	return out;
}
