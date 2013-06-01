/*
 * ColorClass.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef COLORCLASS_H_
#define COLORCLASS_H_

#include "Etage.h"

struct contrainte{
	Etage etage1;
	Etage etage2;
};

class ColorClass {
private:
	contrainte contraintes;
public:
	ColorClass();
	virtual ~ColorClass();
};

#endif /* COLORCLASS_H_ */
