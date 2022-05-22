#include <iostream>
#include <string>
using namespace std;
#define stack_size 50
#define array_size 100

int top = -1;
char Stack[stack_size];

//Stack Functions
bool isStackEmpty(){
    return top == -1;
}
bool isStackFull(){
    return top >= stack_size;
}
void push(char value){
    if(isStackFull())
        cout<<"\tOverflow! Stack is Full.";
    else
        Stack[++top] = value;
}
char pop(){
    if(isStackEmpty()){
        cout<<"\tUnderflow! Stack is Empty.";
        return '\0';
    }
    else
        return Stack[top--];
}
char topElement(){
    if(isStackEmpty()){
        cout<<"\tUnderflow! Stack is Empty.";
        return '\0';
    }
    else
        return Stack[top];
}
//Other Functions
int priority(char op){
    if(op == '+' || op == '-' )
        return 1;
    if(op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}
bool isOperand(char ch){
    return (ch>= 'a' && ch<= 'z') || (ch>= 'A' && ch<= 'Z') || (ch>= '0' && ch<= '9');
}
bool isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' ||ch=='/' ||ch=='%')
        return true;
    else
        return false;
}

int main()
{
    string infix, postfix;
    cout << "Infix Expression : ";
    getline(cin, infix);
    
    for(int i=0; i<infix.length(); i++){
        if(infix[i] == ' ')
            continue;
        
        else if(isOperand(infix[i]))
            postfix += infix[i];
        
        else if(infix[i] == '('){
            push(infix[i]);
            //cout << topElement() << " ";
        }
        
        else if(isOperator(infix[i])){
            while(!isStackEmpty() && topElement() !='(' && priority(topElement()) >= priority(infix[i])){
                postfix += topElement();
                pop();
            }
            push(infix[i]);
            //cout << postfix << endl;
            //cout << topElement() << " ";
        }
        else if(infix[i] == ')'){
            while(!isStackEmpty() && topElement() != '('){
                postfix += topElement();
                pop();
            }
            pop();
        }
    }
    while(!isStackEmpty()){
        postfix += topElement();
        pop();
    }
    
    cout << "\nPostfix Expression " << postfix << endl;
    return 0;
}