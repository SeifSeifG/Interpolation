#include <iostream>
#include "Point.h"
#include "Polynomial.h"

int main()
{
    // Given data points from the image
    Point points[] =
    {
        Point(1.2, 3.41),
        Point(1.5, 5.61),
        Point(1.7, 6.74),
        Point(1.9, 7.11),
        Point(2.0, 7.98)
    };

    // Create an empty polynomial to store the result
    Polynomial Interpolated;

    // Perform interpolation using the first 4 points (order 3 polynomial)
    Point::Interpolate(points, 5,2, Interpolated);

    // Evaluate the polynomial at x = 1.3
    double y_1_3 = Interpolated.InterpolatePoly(1.3);

    // Print the interpolation result
    std::cout << "Interpolated value at x = 1.3: " << y_1_3 << std::endl;

    return 0;
}