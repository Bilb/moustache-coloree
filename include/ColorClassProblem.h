/*
 * ColorClassProblem.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef COLORCLASSPROBLEM_H_
#define COLORCLASSPROBLEM_H_

#include <list>
#include <map>

#include "ColorClass.h"

#include <iostream>

using namespace std;

class ColorClassProblem {
private:
	list<ColorClass*> colorClasses;
	map<unsigned int, unsigned int> rowToSommet;
	map<unsigned int, unsigned int> sommetToRow;

	unsigned int nbSommets;
public:
	ColorClassProblem(string& charpenteFile);
	virtual ~ColorClassProblem();
	void resolve(string charpente);
	void buildProblem(string charpente);



	bool isDifferent(ColorClass & currentColorClass,  unsigned int som1, unsigned int som2);
	friend ostream& operator<<(ostream& out , const ColorClassProblem& problem );
};

#endif /* COLORCLASSPROBLEM_H_ */
