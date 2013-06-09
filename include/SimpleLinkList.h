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
	void pushBack(T* t);
	void insert(T elm, unsigned int indice);
	void removeAllOccurences(T value);



	void print() const;
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
Maillon<T>* SimpleLinkList<T>::begin() const  {
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





template<typename T>
void SimpleLinkList<T>::insert(T elm, unsigned int indice) {
	Maillon<T> * current = begin();
	Maillon<T> * newElem = new Maillon<T>(elm);
	unsigned int currentIndice = 0;


	if(current == NULL) {
		head = newElem;
	}
	else {
		while(current->getNext() != NULL &&  currentIndice < indice) {
			current = current->getNext();
			currentIndice++;
		}
		if(current->getNext() == NULL) {
			current->setNext(newElem);
		}
		else {
			newElem->setNext(current->getNext());
			current->setNext(newElem);
		}
	}
}


template<typename T>
void SimpleLinkList<T>::removeAllOccurences(T value) {
	Maillon<T> * current = begin();

	if(current != NULL) {
		while(current->getNext() != NULL && current->getNext()->getObject() == value) {
			current = current->getNext();
		}
		if(current->getNext() != NULL && current->getNext()->getObject() == value) {
			Maillon<T> * lavictime = current->getNext();
			current->setNext(current->getNext()->getNext());
			delete lavictime;
		}
	}
}

template<typename T>
void SimpleLinkList<T>::print() const {
	Maillon<int>* current = begin();
	if(current != NULL) {
		while(current != NULL) {
			cout << "\n\t\t\titem " << current->getObject() << endl;
			current = current->getNext();
		}
	}
	else {
		cout << "\t\t\tNULL" << endl;
	}
}




#endif /* SIMPLELINKLIST_H_ */
