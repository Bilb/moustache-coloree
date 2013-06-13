/*
 * Maillon.h
 *
 *  Created on: 5 juin 2013
 *      Author: julien
 */

#ifndef MAILLON_H_
#define MAILLON_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

/**
 * Maillon composant une SimpleLinkList
 */
template<typename T>
class Maillon {
private:
	T object;
	Maillon* next;
public:
	Maillon<T>();
	Maillon<T>(T elem);
	virtual ~Maillon();
	T getObject();
	void setObject(T t);
	Maillon* getNext();
	void setNext(Maillon<T>* maillon);

};


template <typename T>
Maillon<T>::Maillon() {
	next = NULL;
}

template <typename T>
Maillon<T>::Maillon(T elem) {
	setObject(elem);
	next = NULL;
}

template <typename T>
Maillon<T>::~Maillon() {
	// TODO Auto-generated destructor stub
}

template<typename T>
T Maillon<T>::getObject() {
	return object;
}

template<typename T>
void Maillon<T>::setObject(T t) {
	object = t;
}

template<typename T>
Maillon<T>* Maillon<T>::getNext() {
	return next;
}

template<typename T>
void Maillon<T>::setNext(Maillon<T>* maillon) {
	next = maillon;
}




template<typename T>
ostream& operator<<(ostream& out, Maillon<T> & maillon) {
	if(maillon == NULL) {
		out << "NULL" << endl;
	}
	else {
		out << maillon.getObject() << " " ;
	}
	return  out;
}


#endif /* MAILLON_H_ */
