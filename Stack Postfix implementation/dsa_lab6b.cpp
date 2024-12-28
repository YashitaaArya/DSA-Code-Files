// EXPERIMENT 6b
// By using the stack implemented earlier, evaluate a postfix algebraic expression with the help of stack.

#include<iostream>
#include<string>
#include<cmath>
#include "dsa_lab5a.cpp"
using namespace std;
int EvaluatePostfix(string s){
    int n=s.length();
    int stack[n];
    // int top=-1;
    for (int i = 0; i < n; i++) {
        if(isdigit(s[i])){
            int operand = s[i]-'0'; // Convert character to integer
            pushVal(stack, n, operand); 
        }else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){
            int operand2 = popOut(stack);
            int operand1 = popOut(stack);
            switch (s[i]) {
                case '+':
                    pushVal(stack, n, operand1 + operand2);
                    break;
                case '-':
                    pushVal(stack, n, operand1 - operand2);
                    break;
                case '*':
                    pushVal(stack, n, operand1 * operand2);
                    break;
                case '/':
                    pushVal(stack, n, operand1 / operand2);
                    break;
                case '^':
                    pushVal(stack, n, pow(operand1, operand2));
                    break;
                default:
                    cout << "Invalid operator! " << endl;
                    break;
            }
        }
    }
    return popOut(stack);
}
int main(){
    string postfix;
    cout << "Enter any postfix expression: ";
    getline(cin, postfix);
    cout << "Result: " << EvaluatePostfix(postfix) << endl;
    return 0;
}