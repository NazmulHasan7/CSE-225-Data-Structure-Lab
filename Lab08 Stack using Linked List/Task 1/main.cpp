/*-------------------------------------------------
Implementation of Stack using Singly Linked list
and Printing stack in forward and reverse order
---------------------------------------------------
Task : 1)Checking validation of an expression
       2)Convert infix notation to Postfix notation
       3)Evaluate the Postfix expression
---------------------------------------------------
By - Nazmul Hasan [1911742042]
Date - 26th March 2020 9:47 PM
-------------------------------------------------*/
#include <iostream>
#include <string.h>
#include "Stack.cpp"
using namespace std;

string RemoveSpaces(string str);
bool isValidExpression(string exp);

string InfixToPostfix(string exp);
int OperatorPrecedence(char op);

float Calculate(float num1, float num2, char op);
float EvaluateExpression(string exp);

int main(void)
{
    char choice = 'y';
    string expression;

    do
    {
        cout <<"Enter an expression to evaluate : ";
        getline(cin, expression);

        string exp = RemoveSpaces(expression);
        cout <<"After removing spaces : "<< exp <<endl;
        bool valid = isValidExpression(exp);

        if(valid)
        {
            string postfix = InfixToPostfix(exp);
            cout <<"Postfix expression : "<< postfix << endl;
            float result = EvaluateExpression(postfix);
            cout <<"Result : " <<result << endl;
        }
        else
        {
            cout <<"Invalid Expression"<<endl;
        }
        cout <<"\nWant to try again ? [Press Y or y] : ";
        cin >> choice;
        cin.ignore();

    }while(choice =='y' || choice == 'Y');
    return 0;
}
/*-----------------------------------------------------------------------
Removing all the spaces
To check the validity of  the given expression whether it is valid or not
------------------------------------------------------------------------*/
string RemoveSpaces (string str)
{
    for(int i=0; str[i]!='\0'; i++)
	{
		if(str[i]==' ')
			str.erase(i,1);
		else if(str[i] =='\t')
            str.erase(i,4);
	}
    return str;
}
/*-------------------------------------------
Checking if the expression is valid or not
Cases : 1) Imbalanced Parentheses
        2) Multiple operator adjacency
---------------------------------------------*/
bool isValidExpression(string exp)
{
    if(!isdigit(exp[0]) && exp[0]!= '(' && exp[0]!= ' ')
        return false;
    /*Checking if multiple operators are together or not
      Checking all the elements are either digit or operator or space or brackets*/
    for(int i=1 ; exp[i]!='\0'; i++)
    {
        if(!isdigit(exp[i]) && exp[i]!='+' && exp[i]!='-' && exp[i]!='*' &&exp[i]!='/' && exp[i]!=')'&& exp[i]!='(')
            return false;
        else if(exp[i]=='+' && (exp[i+1]=='+' || exp[i+1]=='-' || exp[i+1]=='*' || exp[i+1]=='/'))
            return false;
        else if(exp[i]=='-' && (exp[i+1]=='+' || exp[i+1]=='-' || exp[i+1]=='*' || exp[i+1]=='/'))
            return false;
        else if(exp[i]=='*' && (exp[i+1]=='+' || exp[i+1]=='-' || exp[i+1]=='*' || exp[i+1]=='/'))
            return false;
        else if(exp[i]=='/' && (exp[i+1]=='+' || exp[i+1]=='-' || exp[i+1]=='*' || exp[i+1]=='/'))
            return false;
        else
            continue;
    }
    //Checking that parentheses are balanced or not
    Stack<char> s;
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(')
            s.Push('(');
        else if(exp[i] == ')')
            s.Pop();
    }
    //If not balanced
    if(!s.isEmpty())
        return false;
    //If all other cases doesn't return then the expression is valid
    return true;
}
/*------------------------------------------------------------
Converting Infix to Postfix
Problems I've faced :
Separating numbers after converting the expression to postfix.
The way I've solved it :
Add a space(' ') before and after each operator to separate
numbers.
-------------------------------------------------------------*/
string InfixToPostfix(string exp)
{
    Stack <char> s;
    string resultString;
    for(int i=0; exp[i]!='\0' ; i++)
    {
        if(exp[i]=='(')
            s.Push(exp[i]);

        else if(isdigit(exp[i]))
            resultString = resultString + exp[i];

        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            //Adding a space, since the current character is a operator
            resultString += ' ';
            while(!s.isEmpty() && s.Top()!='(' && (OperatorPrecedence(s.Top()) >= OperatorPrecedence(exp[i])))
            {
                resultString = resultString + s.Top();
                //Adding another space after adding the operator to the resulting string
                resultString += ' ';
                s.Pop();
            }
            s.Push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            while(!s.isEmpty() && s.Top()!='(')
            {
                //Same as previous
                resultString += ' ';
                resultString = resultString + s.Top();
                s.Pop();
            }
            if(s.Top() == '(')
                s.Pop();
        }
    }
    //If anything more is in the stack
    while(!s.isEmpty())
    {
        if(s.Top()=='('||s.Top()=='(')
           s.Pop();

        resultString += s.Top();
        s.Pop();
    }
    return resultString;
}
//Checking operator precedence
int OperatorPrecedence(char op)
{
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;

    return 0;
}
//Calculating
float Calculate(float num1, float num2, char op)
{
    switch(op)
    {
        case '+' : return num1 + num2;
        case '-' : return num1 - num2;
        case '*' : return num1 * num2;
        case '/' : return num1 / num2;
    }
}
//Evaluating expression
float EvaluateExpression(string exp)
{
    Stack<char> OpStack;
    Stack<float> numStack;

    for(int i=0; exp[i]!='\0'; i++)
    {
        //If the character is a space then skip it
        if(exp[i]==' ')
            continue;
        //In case of digits
        else if(isdigit(exp[i]))
        {
            int num=0;
            //Handling multiple Digits
            while(isdigit(exp[i]))
            {
                num = (num*10) + (exp[i]-'0');
                i++;
            }
            /*-------------------------------------------------------------
             The iterator i reaches the next character and at some point it
             will reach the character after the number.
             But we are using a for loop that increases the i value by 1
             after each iteration. In this case i++ & i++ increases i by 2
             i-- is used to reduce that i value
             --------------------------------------------------------------*/
            i--;
            numStack.Push(num);
        }
        else
        {
            //Stack maintains the LIFO order so top value should be number 2
            float num2 = numStack.Top();
            numStack.Pop();
            float num1 = numStack.Top();
            numStack.Pop();
            //First calculating and then pushing that result to the stack
            numStack.Push(Calculate(num1,num2,exp[i]));
        }
    }
    return numStack.Top();
}


