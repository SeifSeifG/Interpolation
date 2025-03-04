#pragma once
#include "Term.h"


template <class T>
class Node
{
private:
	T item;
	Node<T>* next;
public:

	//default constructor
	Node() : item(T()), next(nullptr) {} 

	//parametrized constructor
	Node(T input) : item(input), next(nullptr) {}

	//setter
	void setItem(T input)
	{
		item = input;
	}

	void setNext(Node<T>* NextNodeptr)
	{
		next = NextNodeptr;
	}

	//getters
	T getItem() const
	{
		return item;
	}

	Node<T>* getNext() const
	{
		return next;
	}

};