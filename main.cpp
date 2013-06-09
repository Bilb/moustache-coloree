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








	string test("test");
	ColorClassProblem problem(test);

	cout << "problem INITIAL" << problem << endl;
	problem.resolve(test);

	cout << "problem RESOLVED" << problem << endl;


//	SimpleLinkList<int> testList;

/*testList.pushBack(1);
testList.pushBack(2);
testList.pushBack(3);

	testList.print();*/
	return 0;
}


