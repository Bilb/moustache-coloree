/*
 * SimpleLinkList.h
 *
 *  Created on: 5 juin 2013
 *      Author: julien
 */

#ifndef SIMPLELINKLIST_H_
#define SIMPLELINKLIST_H_

#include <iostream>

#include "Maillon.h"

using namespace std;

template <typename T>
class SimpleLinkList {
private:
	Maillon<T>* head;
public:
	SimpleLinkList();
	virtual ~SimpleLinkList();
	Maillon<T>* begin() const;
	Maillon<T>* end();
	void pushBack(T t);
};


template<typename T>
SimpleLinkList<T>::SimpleLinkList() {
	head = NULL;
}

template<typename T>
SimpleLinkList<T>::~SimpleLinkList() {
	// TODO Auto-generated destructor stub
}

template<typename T>
Maillon<T>* SimpleLinkList<T>::begin()  const{
	return head;
}

template<typename T>
Maillon<T>* SimpleLinkList<T>::end() {
	Maillon<T>* maillon = head;

	if(head == NULL) {
		return head;
	}
	else if(maillon->getNext() == NULL) {
		return maillon;
	}
	else {
		while(maillon->getNext() != NULL) {
			maillon = maillon->getNext();
		}
		return maillon;
	}
}

template<typename T>
void SimpleLinkList<T>::pushBack(T t) {
	Maillon<T>* maillon = new Maillon<T>();
	maillon->setNext(NULL);
	maillon->setObject(t);
	if(this->head != NULL) {
		this->end()->setNext(maillon);
	}
	else {
		head = maillon;
	}
}



#endif /* SIMPLELINKLIST_H_ */
