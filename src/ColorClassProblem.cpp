/*
 * ColorClassProblem.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include "../include/ColorClassProblem.h"
#include "../include/ColorClass.h"
#include "../include/Contrainte.h"

#include <assert.h>
#include <string>

#include <iostream>

using namespace std;


ColorClassProblem::ColorClassProblem(string& charpenteFile) {
	if (charpenteFile.length() > 0) {
		//resolve(charpenteFile);
		buildProblem("test");
	}
	else {
		cout << "Impossible de charger le problème depuis le fichier '" << charpenteFile << "'" << endl;
	}


}

ColorClassProblem::~ColorClassProblem() {
	// TODO Auto-generated destructor stub
}


void ColorClassProblem::resolve(string charpente) {
	/*unsigned int colorClassIndex = 0;
	unsigned int loop = 0;
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

		while(loop < nbSommets) {
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
							if(!isDifferent(&currentColorClass, currentEtage1ListColorMaillon.getObject(),currentEtage2ListColorMaillon.getObject())) {
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
	}*/
}

bool ColorClassProblem::isDifferent(ColorClass & currentColorClass, unsigned int som1, unsigned int som2) {
	unsigned int row1 = sommetToRow[som1] - 1;
	unsigned int row2 = sommetToRow[som2] - 1;

	assert (som1 < nbSommets);
	assert (som2 < nbSommets);
	assert (row1 < nbSommets);
	assert (row2 < nbSommets);

	if(row1 > row2) {
		Etage* etage1 = currentColorClass.getContraintes()[row1].getEtage1();
		Etage* etage2 = currentColorClass.getContraintes()[row1].getEtage2();

		assert(etage1 != NULL);
		assert(etage2 != NULL);

		if(etage1->getBitsetColor()[som2] || etage2->getBitsetColor()[som2]) {
			return true;
		}
		else{
			etage2->set(som2);
			return false;
		}
	}
	else {
		Etage* etage1 = currentColorClass.getContraintes()[row2].getEtage1();
		Etage* etage2 = currentColorClass.getContraintes()[row2].getEtage2();

		assert(etage1 != NULL);
		assert(etage2 != NULL);

		if(etage1->getBitsetColor()[som1] || etage2->getBitsetColor()[som1]) {
			return true;
		}
		else{
			etage2->set(som1);
			return false;
		}
	}
}



void ColorClassProblem::buildProblem(string charpenteFile) {
	/* actuellement c'est hardcodé ! */

	nbSommets = 7;
	rowToSommet[0] = 1;
	rowToSommet[1] = 3;
	rowToSommet[2] = 4;
	rowToSommet[3] = 2;
	rowToSommet[4] = 6;
	rowToSommet[5] = 5;
	rowToSommet[6] = 7;

	sommetToRow[1] = 0;
	sommetToRow[3] = 1;
	sommetToRow[4] = 2;
	sommetToRow[2] = 3;
	sommetToRow[6] = 4;
	sommetToRow[5] = 5;
	sommetToRow[7] = 6;


	ColorClass* colorClasse = new ColorClass(nbSommets);
	unsigned int indice;
	for(indice = 0; indice < nbSommets ; indice++) {
		//cout << "\n\n=========setting nbSommet to " << nbSommets << " for contrainte nb:" << indice << endl;
		//colorClasse.getContraintes()[indice].setNbSommet(nbSommets);

		Etage* etage1 = new Etage(nbSommets);
		Etage* etage2 = new Etage(nbSommets);
		switch(indice) {
		case 0:

			break;
		case 1:
			etage1->set(0);
			break;

		case 2:
			etage1->set(0);
			etage1->set(2);
			break;
		case 3:
			etage1->set(0);
			etage1->set(2);
			break;
		case 4:
			etage1->set(1);
			etage1->set(2);
			etage2->set(3);
			break;
		case 5:
			etage1->set(3);
			etage1->set(5);
			etage2->set(0);
			break;
		case 6:
			etage1->set(0);
			etage1->set(4);
			etage2->set(1);
			break;

		default:
			break;
		}

		colorClasse->getContraintes()[indice].setNbSommet(nbSommets,etage1, etage2);

	}

	colorClasses.push_back(colorClasse);
}



ostream& operator<<(ostream& out , const ColorClassProblem& problem ) {
	unsigned int indiceContrainte;
	unsigned int indiceColorClasse = 0;

	out << "PROBLEM :nbSommet : " << problem.nbSommets << endl;

	/* affichage des rangs des sommets */
	for(indiceContrainte = 0; indiceContrainte < problem.nbSommets ; ++indiceContrainte) {
		out << "\trow[" << indiceContrainte << "] :" << problem.rowToSommet.at(indiceContrainte) << endl;
	}

	/* affichage des sommets vers les indexs */
	for(indiceContrainte = 0; indiceContrainte < problem.nbSommets ; ++indiceContrainte) {
		out << "\trow[" << indiceContrainte << "] :" << problem.sommetToRow.at(indiceContrainte) << endl;
	}

	/* affichage de toutes les contraintes */

	list<ColorClass*>::const_iterator it = problem.colorClasses.begin();
	while(it != problem.colorClasses.end()) {
		out << "ColorClasse N°" << indiceColorClasse << ": " << endl << (**it) <<endl;
		it++;
		indiceColorClasse++;
	}



	return out;
}
