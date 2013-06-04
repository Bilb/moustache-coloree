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

class ColorClass {
private:
	Contrainte contraintes;
public:
	ColorClass();
	virtual ~ColorClass();
};

#endif /* COLORCLASS_H_ */
