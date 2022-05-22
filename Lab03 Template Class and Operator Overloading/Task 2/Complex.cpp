#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex()
{
    real = imaginary = 0;
}
Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}
void Complex::print()
{
    cout <<"Real      : "<<real<<endl;
    cout <<"Imaginary : "<<imaginary<<endl;
}
Complex Complex::operator+(Complex a)
{
    Complex sum;
    sum.real = real + a.real;
    sum.imaginary = imaginary + a.imaginary;

    return sum;
}
Complex Complex::operator*(Complex a)
{
    Complex result;
    result.real = real * a.real;
    result.imaginary = imaginary * a.imaginary;

    return result;
}
bool Complex::operator!=(Complex a)
{
    if(real == a.real && imaginary == a.imaginary)
        return false;
    else
        return true;
}
