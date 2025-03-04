#pragma once
#include <iostream>
using namespace std;

class Term
{
private:
	//in the shape Ao(x-xo)(x-x1)(x-x2)...
	
	//Ao
	double coefficient;
	//number of brackets
	int power;
	//array of xo's
	double* constants;

public:
	//default constructor
	Term() : coefficient(0), power(0), constants(nullptr) {}

	//parametrized constructor
	Term(int pow, double coeff)
	{
		SetPower(pow);
		SetCoefficient(coeff);
		constants = new double[power];
	}

	//setters
	void SetCoefficient(double coeff);
	void SetPower(int pow);
	void SetConstant(double Xo, int index);

	//getters
	double getCoefficient();
	int getPower();
	double getConstant (int index);


	//ostream operator overloading
	//upadated for interpolation
	friend ostream& operator << (ostream& os, const Term& term);
};
