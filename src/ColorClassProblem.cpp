/*
 * ColorClassProblem.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include "../include/ColorClassProblem.h"
#include "../include/ColorClass.h"
#include "../include/Contrainte.h"

ColorClassProblem::ColorClassProblem() {
	// TODO Auto-generated constructor stub

}

ColorClassProblem::~ColorClassProblem() {
	// TODO Auto-generated destructor stub
}


void ColorClassProblem::resolve(string charpente) {
	int colorClassIndex = 0;
	int loop = 0;
	bool ambiguous;
	bool mustRestart;
	Maillon currentColorClassMaillon = ColorClassProblem::colorClasses.begin();
	Maillon currentEtage1ListColorMaillon;
	Maillon currentEtage2ListColorMaillon;
	ColorClass currentColorClass = currentColorClassMaillon.colorClass;
	Etage etage1;
	Etage etage2;

	buildProblem(charpente);

	// TODO : Faire un DO WHILE pour le premier !!! Et un IF avant
	while(currentColorClassMaillon.next() != NULL) {
		currentColorClass = currentColorClassMaillon.getObject();

		while(loop < ColorClassProblem::nbSommets) {
			mustRestart = false;
			Contrainte currentConstraint = currentColorClass[loop];

			if(currentConstraint.getEtage2() != NULL) {
				etage2 = currentConstraint.getEtage2();
				currentEtage2ListColorMaillon = etage2.getListColor().begin();

				// TODO : Faire un DO WHILE pour le premier !!! Et un IF avant
				while(currentEtage2ListColorMaillon.next() != NULL) {
					ambiguous = false;

					if(currentConstraint.getEtage1() != NULL) {
						etage1 = currentConstraint.getEtage1();
						currentEtage1ListColorMaillon = etage1.getListColor().begin();

						// TODO : Faire un DO WHILE pour le premier !!! Et un IF avant
						while(currentEtage1ListColorMaillon.next() != NULL) {
							if(!isDifferent(currentEtage1ListColorMaillon.getObject(),currentEtage2ListColorMaillon.getObject())) {
								newColorClass = createNewColorClass(nbSommet, &currentColorClass, row[loop], currentEtage2ListColorMaillon.getObject());
								colorClasses.insert(newColorClass, colorClassIndex);
								ambiguous = true;
								mustRestart = true;
							}

							currentEtage1ListColorMaillon = currentEtage1ListColorMaillon.next();
						}

						if(!ambiguous) {
							etage1.set(currentEtage2ListColorMaillon.getObject());
							etage2.reset(currentEtage2ListColorMaillon.getObject());
						}
					}

					currentEtage2ListColorMaillon = currentEtage2ListColorMaillon.next();
				}
			}

			if(mustRestart) {
				loop = 0;
			}
		}

		currentColorClassMaillon = currentColorClassMaillon.next();
		colorClassIndex ++;
	}
}

void ColorClassProblem::buildProblem(string charpente) {

}
