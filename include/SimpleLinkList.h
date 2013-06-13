/*
 * SimpleLinkList.h
 *
 *  Created on: 5 juin 2013
 *      Author: julien
 */

#ifndef SIMPLELINKLIST_H_
#define SIMPLELINKLIST_H_

#include <iostream>
#include <boost/lexical_cast.hpp>

#include "Maillon.h"

using namespace std;

template <typename T>
class SimpleLinkList {
private:
	/**
	 * tête de cette liste
	 */
	Maillon<T>* head;
public:
	SimpleLinkList();
	virtual ~SimpleLinkList();
	Maillon<T>* begin() const;
	Maillon<T>* end();
	void pushBack(T t);
	void pushBack(T* t);

	/**
	 * Insère l'élément elm à l'indice indice dans cette liste.
	 *
	 */
	void insert(T elm, unsigned int indice);

	/**
	 * Supprime toutes les occurences de l'object values dans cette liste
	 */
	void removeAllOccurences(T value);




	friend ostream& operator<<(ostream& out, SimpleLinkList<T>& list)
	    {
			Maillon<T> * current = list.begin();

			//std::string str = "[ ";
			out << "[ ";
			while(current != NULL) {

				out << boost::lexical_cast<string>( current->getObject() );
				if(current->getNext() != NULL) {
					out << ", ";
				}

				current = current->getNext();
			}
			out << "]";

	    	return out;
	    }

	friend ostream& operator<<(ostream& out, const SimpleLinkList<T>& list)
		    {
				Maillon<T> * current = list.begin();

				//std::string str = "[ ";
				out << "[ ";
				while(current != NULL) {

					out << boost::lexical_cast<string>( current->getObject() );
					if(current->getNext() != NULL) {
						out << ", ";
					}

					current = current->getNext();
				}
				out << "]";

		    	return out;
		    }
};


template<typename T>
SimpleLinkList<T>::SimpleLinkList() {
	head = NULL;
}

template<typename T>
SimpleLinkList<T>::~SimpleLinkList() {
	Maillon<T> * current = begin();
	Maillon<T> * last = current;
	while(current != NULL) {
		last  = current;
		current = current->getNext();
		delete last;
	}
}

template<typename T>
Maillon<T>* SimpleLinkList<T>::begin() const  {
	return head;
}

//todo non nécessaire je crois
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


#endif /* SIMPLELINKLIST_H_ */
