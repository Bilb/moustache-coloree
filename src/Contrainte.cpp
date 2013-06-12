/*
 * Contrainte.cpp
 *
 *  Created on: 4 juin 2013
 *      Author: audric
 */

#include <iostream>
#include <stdio.h>




#include "../include/Contrainte.h"
#include "../include/Etage.h"

Contrainte::Contrainte() : egalite(-1), nbSommet(0) {
	etage1 = NULL;
	etage2 = NULL;
}

Contrainte::Contrainte(unsigned int nbSommet_) : egalite(-1), nbSommet(nbSommet_) {
	if(nbSommet > 0) {
		etage1 = new Etage(nbSommet);
		etage2 = new Etage(nbSommet);
	}
	else {
		etage1 = NULL;
		etage2 = NULL;
	}
}

Contrainte::~Contrainte() {
	delete etage1;
	delete etage2;
}

Etage* Contrainte::getEtage1() {
	return etage1;
}

Etage* Contrainte::getEtage2() {
	return etage2;
}

void Contrainte::setByMagic(map<unsigned int, unsigned int> &rowToSommet, map<unsigned int, unsigned int> &sommetToRow,
		unsigned int nbSommet_, unsigned int indice, Contrainte& src, unsigned int somSearch, unsigned int somReplace)
{
	nbSommet = nbSommet_;
	if(etage1)
		delete etage1;
	if(etage2)
		delete etage2;

	etage1 = new Etage(nbSommet);
	etage2 = new Etage(nbSommet);

	if(src.egalite != (unsigned int )-1 ) {
		egalite = src.egalite;
	}
	else {


		unsigned int rowSearch = sommetToRow[somSearch];

		if(indice == rowSearch) {
			//cas d'égalité : mettre une égalité
			egalite = somReplace;
			if(etage1)
				delete etage1;
			if(etage2)
				delete etage2;

			etage1 = new Etage(nbSommet);
			etage2 = new Etage(nbSommet);

		}
		else if( indice > rowSearch) {

			/* etage1 */
			// parcourir la liste de etage1, si égale à search, faire un set(replace) (et mettre un bool à true), sinon faire un set de celui trouvé dans la liste
			Etage* etg1Src = src.getEtage1();
			Etage* etg2Src = src.getEtage2();



			assert(etg1Src != NULL);
			assert(etg2Src != NULL);
			bool isSetInEtage1 = false;

			Maillon<unsigned int> * current = etg1Src->getListColor().begin();
			while(current != NULL) {
				if(current->getObject() == somSearch) {

					etage1->set(somReplace);
					isSetInEtage1  = true;
				}
				else {

					etage1->set(current->getObject());
				}
				current = current->getNext();
			}


			/* etage2 */
			// parcourir la liste de etage2, si on tombe sur search, alors si bool=true, ne rien faire, il est déjà dans l'étage1
			// 		sinon si bool = false, faire un etage2.set(replace)
			// sinon, ajouter celui trouver dans l'etage2
			current = etg2Src->getListColor().begin();
			while(current != NULL) {
				if(current->getObject() == somSearch && !isSetInEtage1) {
					etage2->set(somReplace);
				}
				else if (!isSetInEtage1){
					etage2->set(current->getObject());
				}

				current = current->getNext();
			}

		}
		else {
			Etage* etg1Src = src.getEtage1();
			Etage* etg2Src = src.getEtage2();

			assert(etg1Src != NULL);
			assert(etg2Src != NULL);

			// copier simplement les deux étages de la src, on a un  rang inférieur au replace : rien à faire de plus
			// parcourir la liste de src.etage1 et faire un set de etage1

			/* etage1 */
			Maillon<unsigned int> * current = etg1Src->getListColor().begin();
			while(current != NULL) {
				etage1->set(current->getObject());
				current = current->getNext();
			}
			/* etage2 */
			current = etg2Src->getListColor().begin();
			while(current != NULL) {
				etage2->set(current->getObject());
				current = current->getNext();
			}
		}
	}

}



void Contrainte::setNbSommet(unsigned int nbSommet_)
{
	nbSommet = nbSommet_;
	if(etage1)
		delete etage1;
	if(etage2)
		delete etage2;

	etage1 = new Etage(nbSommet);
	etage2 = new Etage(nbSommet);
}


void Contrainte::setParams(unsigned int nbSommet_, Etage* etage1_, Etage* etage2_)
{
	nbSommet = nbSommet_;
	if(etage1)
		delete etage1;
	if(etage2)
		delete etage2;

	etage1 = etage1_;
	etage2 = etage2_;
}


ostream& operator<<(ostream& out ,  Contrainte& cont ) {
	out << "\tnbSommets: " << cont.getNbSommet() << endl;

	if(cont.egalite < cont.getNbSommet()) {
		out << "\t\t\tegalite:" << cont.egalite << endl;
	}
	else {
		if(cont.getEtage1()!= NULL)
			out << "\t\tetage1: " << *cont.getEtage1() << endl;
		else
			out << "\t\tetage1: " << "NULL" << endl;

		if(cont.getEtage2()!= NULL)
			out << "\t\tetage2: " << *cont.getEtage2() << endl;
		else
			out << "\t\tetage2: " << "NULL" << endl;
	}


	return out;
}

