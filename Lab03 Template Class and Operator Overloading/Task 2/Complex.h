#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class Complex{

private :
    double real;
    double imaginary;
public :
    Complex();
    Complex(double,double);
    void print();
    Complex operator+ (Complex);
    Complex operator* (Complex);
    bool operator!= (Complex);
};
#endif // COMPLEX_H_INCLUDED
