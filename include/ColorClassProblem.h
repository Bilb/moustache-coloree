/*
 * ColorClassProblem.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef COLORCLASSPROBLEM_H_
#define COLORCLASSPROBLEM_H_

#include <map>

#include "SimpleLinkList.h"
#include "ColorClass.h"

#include <iostream>

using namespace std;

/**
 * Cette classe est la classe principale : c'est elle qui résoud un problème de coloration
 */
class ColorClassProblem {
private:
	/**
	 * map permettant l'accès au numéro de sommet, en connaissant leurs rang
	 */
	map<unsigned int, unsigned int> rowToSommet;

	/**
	 * map permettant l'accès au rang des sommets, en connaissant leurs numéro
	 */
	map<unsigned int, unsigned int> sommetToRow;

	/**
	 * Liste des colorClasses associées à ce problème
	 */
	SimpleLinkList<ColorClass*> colorClasses;


	/**
	 * Nombre de sommets de ce problème
	 */
	unsigned int nbSommets;

	/**
	 * Retourne le som dont le rang est le plus grand, en accord avec la map sommetToRow
	 */
	unsigned int getSomWithMaxRow(unsigned int som1, unsigned int som2);

	/**
	 * Parse le fichier charpente afin de construire un problème
	 */
	void buildProblem(string charpente);

public:
	/**
	 * Charge et parse le fichier charpenteFile afin de construire le problème initial
	 */
	ColorClassProblem(string& charpenteFile);

	/**
	 * Résouds ce problème
	 */
	void resolve();


	/**
	 * Renvoie true si les sommet 1 et 2 sont forcément différent l'un de
	 * l'autre dans la colorClasse currentColorClass.
	 */
	//todo fait un peu plus que ça ;)
	bool isDifferent(ColorClass & currentColorClass,  unsigned int som1, unsigned int som2);

	friend ostream& operator<<(ostream& out ,  ColorClassProblem& problem );
	virtual ~ColorClassProblem();
};

#endif /* COLORCLASSPROBLEM_H_ */
