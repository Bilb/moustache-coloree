/*
 * main.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include <iostream>

#include "include/SimpleLinkList.h"
#include "include/ColorClass.h"
#include "include/ColorClassProblem.h"
#include "include/Etage.h"
#include "include/Contrainte.h"

using namespace std;

int main(int argc, char* argv[]) {
	ColorClass colorClass(3);
	SimpleLinkList<int>* maList = new SimpleLinkList<int>();

	maList->pushBack(1);
	maList->pushBack(2);
	maList->pushBack(3);
	cout << "test" << endl;



	Maillon<int>* maillon = maList->begin();

	while(maillon->getNext() != NULL) {
		cout << maillon->getObject() << endl;
		maillon = maillon->getNext();
	}
	cout << maillon->getObject() << endl;

	cout << "colorClass " << colorClass << endl;
	return 0;
}


