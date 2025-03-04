#pragma once
#include "Polynomial.h"

class Point
{

private:
	double x, y;

	static double DividedDiff(Point p1, Point p2)
	{
		double result = (p2.y - p1.y) / (p2.x - p1.x);
		return result;
	} 


public:
	Point() : x(0), y(0) {}
	Point(double inX, double inY) : x(inX), y(inY) {}

	void setX(double inX)
	{
		x = inX;
	}

	void setY(double inY)
	{
		y = inY;
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y; 
	}

	//make sure to input DivDiffArrInput as empty array (un inisialized)
	//make sure to input orderDivDiff = 0
	static void Interpolate(Point* points, int number, int degree, Polynomial& result,double* DivDiff = nullptr, int orderDivDiff = 1)
	{
		//when the order of interpolated polynimial
		//reaches (number of points - 1)
		//this marks our end of journey
		if (orderDivDiff > degree)
			return;

		//get first divided difference column
		if (orderDivDiff == 1 || DivDiff == nullptr)
		{
			//add Xo
			Term ConstTerm(0, points[0].getX());

			result.AddTerm(ConstTerm);

			//number of terms of 1st column, i.e. in DivDiff y1
			DivDiff = new double[number - orderDivDiff];

			//get DivDiff terms
			for (int i = 0; i < (number - orderDivDiff); i++)
			{
				DivDiff[i] = DividedDiff(points[i], points[i + 1]);
			}
			
			//create new term of order (number - 1)
			Term Nterm(orderDivDiff, DivDiff[0]);

			//setting Xo
			Nterm.SetConstant(points[0].getX(), 0);

			//add it to the polynomial
			result.AddTerm(Nterm);

			//increment to start getting DivDiff y2
			orderDivDiff++;

			Interpolate(points, number , degree, result, DivDiff, orderDivDiff);
		}
		else
		{
			// assume 5 points
			// scenario 1 : assume we are at 1st rec call 
			// DivDiff has 4 terms, OrderDivDiff is 2

			// scenario 2 : assume we are at 2st rec call 
			// DivDiff has 3 terms, OrderDivDiff is 3

			//step 1: create new arrat of DivDiff
			double* NewDivDiff = new double[number - orderDivDiff];

			//step 2: populate it
			for (int i = 0; i < (number - orderDivDiff - 1); i++)
			{
				NewDivDiff[i] = (DivDiff[i + 1] - DivDiff[i]) / (points[i + orderDivDiff].getX() - points[i].getX());
			}

			//step 3: create new term
			Term Nterm(orderDivDiff, NewDivDiff[0]);

			//step 4: add x0,x1,x2 ...
			for (int i = 0; i < Nterm.getPower(); i++)
			{
				Nterm.SetConstant(points[i].getX(), i);
			}

			//add it to the polynomial
			result.AddTerm(Nterm);

			//step 5: no need for old divided diff (memory waste)
			delete[] DivDiff;

			orderDivDiff++;

			Interpolate(points, number, degree, result, NewDivDiff, orderDivDiff);
		}
	}
};