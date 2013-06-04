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


using namespace std;


class ColorClassProblem {
private:
	list<ColorClass> colorClasses;
	map<int,int> row; //map finalement ici : clé = sommet
public:
	ColorClassProblem();
	virtual ~ColorClassProblem();
	void resolve(string charpente);
	void buildProblem(string charpente);
};

#endif /* COLORCLASSPROBLEM_H_ */
