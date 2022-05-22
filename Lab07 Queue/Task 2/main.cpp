/*
 Name : Nazmul Hasan
 ID   : 1911742042
 Problem : Print binary numbers up to N(user input)
*/

#include <iostream>
#include<string>
#include "quetype.cpp"

using namespace std;

int main(void)
{
    /* Creating an QueType Object */
    QueType <string> binary;

    int num;
    /* Taking user input */
    cout << "Enter N [This program will print binary numbers from 1 to N] : ";
    cin >> num;
    cout << endl;

    /* A for loop to iterate numbers from 1 to N */
    for(int i=1; i<=num;  i++)
    {
        /* bin is used to store the binary digits */
        int bin;
        int n = i;
        /* A string object that is initialized to null
          after every iteration */
        string binaryString = "";

        while(n>0)
        {
            bin = n%2;
            if(bin == 0){
                binaryString+="0";
            }
            else{
                binaryString+="1";
            }
            n = n/2;
        }
        /* Since, in the upper loop we are storing each digits
           in reverse order. We can use another string object to
           reverse that string. So, we will get actual binary value
           in temp */
        string temp;
        for(int j= binaryString.length()-1; j>=0; j--)
        {
            temp+=binaryString.at(j);
        }
        /* Enqueue */
        binary.Enqueue(temp);
     }

     /* Dequeue*/
     for(int i=0; i<num; i++)
     {
         string temp;
         binary.Dequeue(temp);
         cout<<i+1<<"'s binary = "<<temp<<endl;
         cout<<endl;
     }

}
