/*
 * main.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include <iostream>


#include "include/ColorClass.h"
#include "include/ColorClassProblem.h"
#include "include/Etage.h"
#include "include/Contrainte.h"

using namespace std;

int main(int argc, char* argv[]) {
	string test("test");
	ColorClassProblem problem(test);


	cout << "problem " << problem << endl;
	return 0;
}


