/*
 * Contrainte.h
 *
 *  Created on: 4 juin 2013
 *      Author: audric
 */

#ifndef CONTRAINTE_H_
#define CONTRAINTE_H_

#include "../include/Etage.h"

class Contrainte {
private:
	Etage etage1;
	Etage etage2;
public:
	Contrainte();
	virtual ~Contrainte();
};

#endif /* CONTRAINTE_H_ */
