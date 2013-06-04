/*
 * ColorClass.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef COLORCLASS_H_
#define COLORCLASS_H_

#include "Etage.h"
#include "../include/Contrainte.h"


#include <iostream>


using namespace std;


class ColorClass {
private:
	Contrainte* contraintes;
	unsigned int nbSommet;

public:
	ColorClass(unsigned int nbSommet);
	ColorClass(unsigned int nbSommet, ColorClass& src, unsigned int search, unsigned int replace);


	friend ostream& operator<<(ostream& out , const ColorClass& colorClass );

	virtual ~ColorClass();
};

#endif /* COLORCLASS_H_ */
