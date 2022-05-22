#include <iostream>
#include <string>
#include "StackType.cpp"

using namespace std;

int main(void)
{
    StackType <char> obj;
    char ch;
    do{
        string input;
        cout << "Enter string of parentheses : ";
        cin >> input;

        for(int i=0; i<input.length(); i++){
            if(input.at(i) == '(')
                obj.Push('(');
            else if(input.at(i) == ')')
                obj.Pop();
        }
        if(obj.isEmpty())
            cout << "\nBalanced";
        else
            cout << "\nNot balanced";

        cout << "\nPress 0 to try again or any key to exit : ";
        cin >> ch;
        cin.ignore();

    }while(ch == '0');
    return 0;
}
