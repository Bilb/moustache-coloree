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
#include <boost/date_time/local_time/local_time.hpp>


#include <string>
#include <iostream>


#include "include/SimpleLinkList.h"
#include "include/ColorClass.h"
#include "include/ColorClassProblem.h"
#include "include/Etage.h"
#include "include/Contrainte.h"

namespace qi = boost::spirit::qi;
namespace fusion = boost::fusion;
namespace pt = boost::posix_time;


int main(int argc, char* argv[]) {
	string test("./test.txt");

	pt::ptime start = pt::microsec_clock::universal_time();
	ColorClassProblem problem(test);
	//cout << "problem INITIAL" << problem << endl;
	problem.resolve();

	pt::ptime end = pt::microsec_clock::universal_time();

	cout << "problem RESOLVED" << problem << endl;


	pt::time_duration dur = end - start;
	cout << "resolution took : " << dur.total_microseconds() << " micro secondes" << endl;

	return 0;
}


