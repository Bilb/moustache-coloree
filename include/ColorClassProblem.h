/*
 * ColorClassProblem.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef COLORCLASSPROBLEM_H_
#define COLORCLASSPROBLEM_H_

#include <list>

#include "ColorClass.h"


using namespace std;


class ColorClassProblem {
private:
	list<ColorClass> colorClasses;
public:
	ColorClassProblem();
	virtual ~ColorClassProblem();
};

#endif /* COLORCLASSPROBLEM_H_ */
