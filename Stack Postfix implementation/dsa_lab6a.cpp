// EXPERIMENT 6a
// By using the stack implemented earlier, write a program to convert infix algebraic expression to postfix algebraic expression with 
// the help of stack.

#include<iostream>
#include<string>
#include "dsa_lab5a.cpp"
using namespace std;
int top=-1;
void push(char stack[], int &top, int size, char val){
    if(top==size-1){
        cout << "Condition of Overflow\n";
        return;
    }else{
        top=top+1;
        stack[top]=val;
    }
}
void pop(char stack[], int &top){
    if (top==-1){
        cout << "Condition of Underflow\n";
        return;
    }else{
        top=top-1;
        return;
    }
}
int orderOfPrecedence(char c){
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
char associativity(char c){
    if(c=='^')
        return 'R';
    else
        return 'L';
}
void InfixToPostfix(string infix) {
    char stack[100];
    int top = -1;
    int size=infix.length();
    string result; 
    for (int i=0; i<infix.length(); i++) {
        char check = infix[i];
        if ((check >= 'a' && check <= 'z') || (check >= 'A' && check <= 'Z') || (check >= '0' && check <= '9')){
            result=result+check;
        }else if (check == '('){
            push(stack, top, size, check);
        }else if (check == ')'){
            while (stack[top] != '('){
                result=result+stack[top];
                pop(stack, top);
            }
            pop(stack, top);
        }else{
            while (top != -1 && orderOfPrecedence(infix[i]) <= orderOfPrecedence(stack[top]) && associativity(infix[i]) == 'L'){
                result=result+stack[top];
                pop(stack, top);
            }
            push(stack, top, size, check);
        }
    }
    while (top!=-1) {
        result=result+stack[top];
        pop(stack, top);
    }
    cout << result << endl;
}
int main() {
    string infix;
    cout << "Enter any infix expression: ";
    getline(cin, infix);
    InfixToPostfix(infix);
    return 0;
}
