/*
 * Etage.h
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */

#ifndef ETAGE_H_
#define ETAGE_H_

#include <list>
#include <boost/dynamic_bitset.hpp>

class Etage {
private:
	bool useLinkList;
	std::list<int> listColor;
	boost::dynamic_bitset<> bitsetColor;
public:
	Etage();
	virtual ~Etage();
};

#endif /* ETAGE_H_ */
