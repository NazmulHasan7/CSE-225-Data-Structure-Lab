#include <iostream>
#include "Complex.cpp"

using namespace std;

void takeInput(int *r, int *i)
{
    cout <<"Real      : ";
    cin >> *r;
    cout <<"Imaginary : ";
    cin >> *i;
}

int main(void)
{
    //Creating objects
    int real, imaginary;
    cout<<"Object 1\n"<<endl;

    takeInput(&real, &imaginary);
    Complex obj1(real,imaginary);

    cout<<"\nObject 2\n"<<endl;

    takeInput(&real, &imaginary);
    Complex obj2(real,imaginary);

    Complex sum = obj1 + obj2;
    cout <<"\nSummation of object 1 & object 2 is : "<<endl;
    sum.print();

    Complex mul = obj1 * obj2;
    cout <<"\nMultiplication of object 1 & object 2 is : "<<endl;
    mul.print();

    bool isNotEqual = obj1 != obj2;
    cout <<"\nAre object 1 & object 2 are not equal ? "<<isNotEqual<<endl;

    return 0;
}
