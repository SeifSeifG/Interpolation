#include "Term.h"




	//setters
	void Term :: SetCoefficient(double coeff)
	{
		coefficient = coeff;
	}

	void Term:: SetPower(int pow)
	{
		power = (pow > 0)? pow : 0;
	}

	void Term :: SetConstant(double Xo, int index)
	{
		if (index > power || index < 0)
			return;
		constants[index] = Xo;
	}


	//getters
	double Term :: getCoefficient()
	{
		return coefficient;
	}

	int Term :: getPower()
	{
		return power;
	}

	double Term::getConstant(int index)
	{
		if (index > power || index < 0)
			return 0;
		return constants[index];
	}

	//ostream operator implementation
	ostream& operator << (ostream& os, const Term& term)
	{
		//Ao(x - xo)
		//Ao
		os << term.coefficient;

		//(x-xo)
		for (int i = 0; i < term.power; i++)
		{
			os << "(x ";
			if (term.coefficient > 0)
				os << "- " << term.constants[i] << ")";
			else if (term.coefficient < 0)
				os << "+ " << -term.constants[i] << ")";
			else
				os << "(x)";
		}

		return os;
	}


