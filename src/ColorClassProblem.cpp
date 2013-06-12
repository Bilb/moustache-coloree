/*
 * ColorClassProblem.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include "../include/ColorClassProblem.h"
#include "../include/ColorClass.h"
#include "../include/Contrainte.h"
#include "../include/Maillon.h"
#include "../include/SimpleLinkList.h"
#include "../skeletonParser.h"

#include <assert.h>
#include <string>


#include <iostream>



ColorClassProblem::ColorClassProblem(string& charpenteFile) {
	if (charpenteFile.length() > 0) {
		buildProblem(charpenteFile);
	}
	else {
		cout << "Impossible de charger le probleme depuis le fichier '" << charpenteFile << "'" << endl;
	}


}

ColorClassProblem::~ColorClassProblem() {
	// TODO Auto-generated destructor stub
}


void ColorClassProblem::resolve(string charpente) {
	unsigned int colorClassIndex = 0;
	unsigned int loop = 0;
	bool ambiguous;
	bool mustRestart;




	Maillon<ColorClass*>* currentColorClassMaillon = colorClasses.begin();
	Maillon<unsigned int>* currentEtage1ListColorMaillon;
	Maillon<unsigned int>* currentEtage2ListColorMaillon;
	ColorClass* currentColorClass = currentColorClassMaillon->getObject();


	Etage* etage1;
	Etage* etage2;





	// TODO : Traiter le dernier !!!
	while(currentColorClassMaillon != NULL) {
		currentColorClass = currentColorClassMaillon->getObject();



		Contrainte* currentConstraint;
		loop = 0;
		while(loop < nbSommets) {
			mustRestart = false;

			currentConstraint = &(currentColorClass->getContraintes())[loop];


			assert(currentConstraint != NULL);


			mustRestart = false;



			if(currentConstraint->getEtage2() != NULL) {
				etage2 = currentConstraint->getEtage2();
				currentEtage2ListColorMaillon = etage2->getListColor().begin();


				while(currentEtage2ListColorMaillon != NULL) {

					ambiguous = false;

					if(currentConstraint->getEtage1() != NULL) {
						etage1 = currentConstraint->getEtage1();
						currentEtage1ListColorMaillon = etage1->getListColor().begin();

						while(currentEtage1ListColorMaillon != NULL) {
							if(!isDifferent(*currentColorClass, currentEtage1ListColorMaillon->getObject(),currentEtage2ListColorMaillon->getObject())) {
								unsigned int search = getSomWithMaxRow(currentEtage1ListColorMaillon->getObject(),currentEtage2ListColorMaillon->getObject());
								ColorClass * newColorClass = new ColorClass(rowToSommet,
										sommetToRow,
										nbSommets,
										*currentColorClass,
										search,
										currentEtage2ListColorMaillon->getObject());

								colorClasses.insert(newColorClass, colorClassIndex);
								ambiguous = true;
								mustRestart = true;
							}

							currentEtage1ListColorMaillon = currentEtage1ListColorMaillon->getNext();
						}

						if(!ambiguous) {
							etage1->set(currentEtage2ListColorMaillon->getObject());
							etage2->reset(currentEtage2ListColorMaillon->getObject());
						}

					}

					currentEtage2ListColorMaillon = currentEtage2ListColorMaillon->getNext();

				}
			}

			loop++;
			if(mustRestart) {
				loop = 0;
			}



		}


		currentColorClassMaillon = currentColorClassMaillon->getNext();
		colorClassIndex ++;
	}
}


bool ColorClassProblem::isDifferent(ColorClass & currentColorClass, unsigned int som1, unsigned int som2) {
	unsigned int row1 = sommetToRow[som1];
	unsigned int row2 = sommetToRow[som2];


	assert (som1 < nbSommets);
	assert (som2 < nbSommets);
	assert (row1 < nbSommets);
	assert (row2 < nbSommets);
	if(som1 == som2)
		return true;

	if(row1 > row2) {
		Etage* etage1 = currentColorClass.getContraintes()[row1].getEtage1();
		Etage* etage2 = currentColorClass.getContraintes()[row1].getEtage2();

		assert(etage1 != NULL);
		assert(etage2 != NULL);


		if(etage1->test(som2) || etage2->test(som2)) {
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

		if(etage1->test(som1) || etage2->test(som1)) {
			return true;
		}
		else{
			etage2->set(som1);
			return false;
		}
	}
}



void ColorClassProblem::buildProblem(string charpenteFile) {
/*	nbSommets = 7;
	rowToSommet[0] = 1;
	rowToSommet[1] = 3;
	rowToSommet[2] = 4;
	rowToSommet[3] = 2;
	rowToSommet[4] = 6;
	rowToSommet[5] = 5;
	rowToSommet[6] = 7;

	sommetToRow[1-1] = 0;
	sommetToRow[3-1] = 1;
	sommetToRow[4-1] = 2;
	sommetToRow[2-1] = 3;
	sommetToRow[6-1] = 4;
	sommetToRow[5-1] = 5;
	sommetToRow[7-1] = 6;


	cout << "---------building problem --------------" <<endl;
	ColorClass* colorClasse = new ColorClass(nbSommets);

	//cout << "---------colorClasse* " << colorClasse << "--------------" <<endl;
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


		colorClasse->getContraintes()[indice].setParams(nbSommets,etage1, etage2);

	}
	colorClasses.pushBack(colorClasse);
	cout << "---------END OF BUILDER--------------" <<endl;
*/



	problemType pb;


	if (parseFile(charpenteFile, pb)) {


		nbSommets = pb.nbSommet;
		ColorClass* colorClasse = new ColorClass(nbSommets);

		// build ColorClass
		rowType row;
		for(unsigned int indice = 0; indice < nbSommets ; indice++) {
			row = pb.rows.at(indice);
			Etage* etage1 = new Etage(nbSommets);
			etage1->setFromList(row.etage1);

			Etage* etage2 = new Etage(nbSommets);
			etage2->setFromList(row.etage2);

			colorClasse->getContraintes()[indice].setParams(nbSommets,etage1, etage2);

			rowToSommet[indice] = row.number - 1;
			sommetToRow[row.number - 1 ] = indice;
		}



		colorClasses.pushBack(colorClasse);

	}

}


unsigned int ColorClassProblem::getSomWithMaxRow(unsigned int som1, unsigned int som2) {

	assert(som1 < nbSommets);
	assert(som2  < nbSommets);

	if(sommetToRow[som1] > sommetToRow[som2])
		return som1;
	else
		return som2;


}




ostream& operator<<(ostream& out ,  ColorClassProblem& problem ) {
	unsigned int indiceContrainte;
	unsigned int indiceColorClasse = 0;

	//out << "PROBLEM :nbSommet : " << problem.nbSommets << endl;

	/* affichage des rangs des sommets */
	/*for(indiceContrainte = 0; indiceContrainte < problem.nbSommets ; ++indiceContrainte) {
		out << "\trow[" << indiceContrainte << "] :" << problem.rowToSommet.at(indiceContrainte) << endl;
	}
	out << endl << endl;
*/
	/* affichage des sommets vers les indexs */
	/*for(indiceContrainte = 0; indiceContrainte < problem.nbSommets ; ++indiceContrainte) {
		out << "\trow[" << indiceContrainte << "] :" << problem.sommetToRow.at(indiceContrainte) << endl;
	}
*/
	/* affichage de toutes les contraintes */
	Maillon<ColorClass*>* currentColorClassMaillon = problem.colorClasses.begin();
	// TODO : Traiter le dernier !!!
	cout << endl <<endl <<endl <<endl <<endl;
	while(currentColorClassMaillon != NULL) {
		out << "ColorClasse Num " << indiceColorClasse << ": " <<endl;
		out << *(currentColorClassMaillon->getObject()) << endl;
		currentColorClassMaillon = currentColorClassMaillon->getNext();
		indiceColorClasse++;
	}
	cout << endl <<endl <<endl <<endl <<endl;

	return out;
}
