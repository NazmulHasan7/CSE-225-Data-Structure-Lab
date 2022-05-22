/*---------RECURSION-----------*
 * 1)Fibonacci                 *
 * 2)Factorial                 *
 * 3)Sum of Digits             *
 * 4)Find Minimum in Array     *
 * 5)Find Maximum in Array     *
 * 6)Convert Decimal to Binary *
 * 7)Convert Binary to Decimal *
 * 8)Sum of Series             *
 * 9)Reverse of a number       *
 *-----------------------------*
*/
#include <iostream>
#include <math.h>
using namespace std;

int Fibonacci(int n);
int Factorial(int n);

int SumOfDigits(int n);
int ReverseOfNumber(int n);

int FindMin(int arr[], int len);
int FindMax(int arr[], int len);

int DecimalToBinary(int n);
int BinaryToDecimal(int n);

double SumOfSeries(int n);

int main(void)
{
    cout <<"8th Fibonacci : "<< Fibonacci(8) << endl;
    cout <<"\nFactorial of 5 --> 5! : "<< Factorial(5) << endl;
    cout <<"\nSum Of Digits of 123 : "<< SumOfDigits(123) << endl;
    cout <<"\nReverse of Number 123 : "<< ReverseOfNumber(123) << endl;

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout <<"\nMinimum value in the array : "<< FindMin(arr,10) << endl;
    cout <<"\nMaximum value in the array : "<< FindMax(arr,10) << endl;

    cout <<"\nDecimal 10 is Binary : "<< DecimalToBinary(10) << endl;
    cout <<"\nBinary 10101 is Decimal : "<< BinaryToDecimal(10101) << endl;

    cout <<"\nSum of Series 1 + 1/2 + 1/4 + 1/8 + 1/16 : "<< SumOfSeries(4) << endl;
    return 0;
}
//FIBONACCI
int Fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}
//FACTORIAL
int Factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n-1);
}
//SUM OF DIGITS
int SumOfDigits(int n)
{
    if(n == 0)
        return 0;
    else
        return (n % 10) + (SumOfDigits(n / 10));
}
//REVERSE OF NUMBER
int ReverseOfNumber(int n)
{
    int digits = (int) log10(n);

    if(n == 0)
        return 0;
    else
        return ((n % 10) * pow(10, digits))+ ReverseOfNumber(n / 10);
}
//FINDING MINIMUM OF AN ARRAY
int FindMin(int arr[], int len)
{
    if(len == 0)
        return arr[0];

    if(arr[len-1] < FindMin(arr, len-1))
        return arr[len-1];
    else
        return (FindMin(arr, len-1));
}
//FINDING MAXIMUM OF AN ARRAY
int FindMax(int arr[], int len)
{
    if(len == 0)
        return arr[0];
    else if(arr[len-1] > FindMax(arr,len-1))
        return arr[len-1];
    else
        return FindMax(arr, len-1);
}
//DECIMAL TO BINARY
int DecimalToBinary(int n)
{
    if(n == 0)
        return 0;
    else
        return(n%2) + 10*DecimalToBinary(n/2);
}
//BINARY TO DECIMAL
int BinaryToDecimal(int n)
{
    if(n == 0)
        return 0;
    else
        return(n%10) + 2*BinaryToDecimal(n/10);
}
//SUM OF SERIES
double SumOfSeries(int n)
{
    if(n == 0)
        return 1;
    else
        return(1.0 / pow(2,n) + SumOfSeries(n-1));
}
