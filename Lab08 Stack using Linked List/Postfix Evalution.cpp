#include <iostream>
#include <string>
using namespace std;

#define stack_size 50
#define array_size 100

int top = -1;
int Stack[stack_size];

//Stack Functions
bool isStackEmpty(){
    return top == -1;
}
bool isStackFull(){
    return top >= stack_size;
}
void push(int value){
    if(isStackFull())
        cout<<"\tOverflow! Stack is Full.";
    else
        Stack[++top] = value;
}
void pop(){
    if(isStackEmpty())
        cout<<"\tUnderflow! Stack is Empty.";
    else
        top--;
}
int topElement(){
    if(isStackEmpty()){
        cout<<"\tUnderflow! Stack is Empty.";
        return 0;
    }
    else
        return Stack[top];
}
//Other Functions
bool isDigit(char ch){
    return (ch >= '0' && ch <= '9');
}
bool isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}
int Calculate(int num1, int num2, char op){
    if(op == '+')
        return num1 + num2;
    else if(op == '-')
        return num1 - num2;
    else if(op == '*')
        return num1 * num2;
    else if(op == '/')
        return num1 / num2;
    else
        return num1 % num2;
}
int EvaluatePostfix(string postfix)
{
    for(int i=0; i<postfix.length(); i++){
        if( postfix[i] == ' ')
            continue;
        else if(isOperator(postfix[i])){
            float num2 = topElement();
            pop();
            float num1 = topElement();
            pop();
            int result = Calculate(num1, num2, postfix[i]);
            push(result);
        }
        else if(isDigit(postfix[i])){
            int number=0;
            while(isDigit(postfix[i]) && i<postfix.length()){
                number = number * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            push(number);
        }
    }
    return topElement();
}
int main()
{
    string postfix;
    cout << "postfix expression ? ";
    getline(cin, postfix);
    
    cout << "Result " << EvaluatePostfix(postfix) << endl;
    return 0;
}