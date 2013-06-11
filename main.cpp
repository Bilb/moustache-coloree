/*
 * main.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>
#include <boost/spirit/include/karma_eps.hpp>

 /* fusion */
#include <boost/fusion/adapted/adt/adapt_adt.hpp>
#include <boost/fusion/include/adapt_adt.hpp>

#include <string>
#include <iostream>

#include "include/SimpleLinkList.h"
#include "include/ColorClass.h"
#include "include/ColorClassProblem.h"
#include "include/Etage.h"
#include "include/Contrainte.h"

namespace qi = boost::spirit::qi;
namespace fusion = boost::fusion;

/*
int main(int argc, char* argv[]) {

	string test("test");
	ColorClassProblem problem(test);

	cout << "problem INITIAL" << problem << endl;
	problem.resolve(test);

	cout << "problem RESOLVED" << problem << endl;


	return 0;
}

*/
