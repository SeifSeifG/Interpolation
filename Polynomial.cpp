#pragma once
#include "Polynomial.h"


//data members
/*	Node<Term>* head;
	int degree;
*/



void Polynomial::AddTerm(Term& term)
{
	//check if I already have this term
	Node<Term>* AlreadyThere = get_ptr_to(term.getPower());

	//if I already have a term of this power in th polynomial
	if (AlreadyThere)
	{
		//get old coefficient of power n in the list
		double oldCoefficient = AlreadyThere->getItem().getCoefficient();

		//add it to the new coefficient
		AlreadyThere->getItem().SetCoefficient(oldCoefficient + term.getCoefficient());
	}

	else if (term.getPower() > degree)
	{
		//this repreents a new head
		Node<Term>* Nnode = new Node<Term>(term);

		// If list is empty or new term has highest power
		if (!head || term.getPower() > head->getItem().getPower())
		{
			Nnode->setNext(head);
			head = Nnode;

			//adjust highest degree
			degree = term.getPower();
		}

	}
	else 
	//term.getPower() < degree 
	//or (degree = P1.degree = 0) //special case
	{
		//new node at a general place
		Node<Term>* Nnode = new Node<Term>(term);

		if (!head)
		{
			Nnode->setNext(head);
			head = Nnode;
		}
		else
		{
			Node<Term>* prev = nullptr;
			Node<Term>* curr = head;


			while (curr && curr->getItem().getPower() > term.getPower())
			{
				prev = curr;
				curr = curr->getNext();
			}

			// Insert in correct position
			prev->setNext(Nnode);
			Nnode->setNext(curr);
		}

		// Find correct insertion point
	}
}

void Polynomial::PrintPoly() const
{
	Node<Term>* ptr = head;

	//stops at last node
	//avoid extra + sign for last term
	while (ptr->getNext() && ptr)
	{
		cout << ptr->getItem() << "+";
		ptr = ptr->getNext();
	}

	//print last term
	cout << ptr->getItem();
}

double Polynomial::getCoefficient(int power) const
{
	if (get_ptr_to(power))
		return get_ptr_to(power)->getItem().getCoefficient();
	else
		return 0;

}

double Polynomial :: InterpolatePoly (double x) const
{
	Node<Term>* ptr = head;

	double result = 0;

	if (!ptr)
		return 0;

	while (ptr)
	{
		double TermResult = 1;

		for (int i = 0; i < ptr->getItem().getPower(); i++)
		{
			//perform (x-xo)(x-x1)(x-x2)...
			TermResult *= (x - ptr->getItem().getConstant(i));
		}
		
		//multiply by divided difference
		TermResult *= ptr->getItem().getCoefficient();

		//upadate bigger result
		result += TermResult;

		//traverse
		ptr = ptr->getNext();
	}

	return result;
}