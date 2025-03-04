#pragma once
#include "Node.h"

class Polynomial {
private:
    Node<Term>* head;
    int degree;

    //utility function
    Node<Term>* get_ptr_to(int power) const
    {
        Node<Term>* ptr = head;

        //if the Polynimial is empty
        if (!ptr)
            return ptr;

        while (ptr)
        {
            if (ptr->getItem().getPower() == power)
                break;
            ptr = ptr->getNext();
        }

        return ptr;
    }

public:
    // Constructor
    Polynomial() : head(nullptr), degree(0) {}

    // Methods
    void AddTerm(Term& term);
    void PrintPoly() const;
    double getCoefficient(int power) const;

    double InterpolatePoly(double x) const;


    //bool setCoefficient(float NewCoeff, int power);
    //Polynomial AddPoly(const Polynomial& P1);
};