#include<iostream>
#include<cmath>
using namespace std;
// Create a calculator that takes a number, a basic math operator (+,-,*,/,^), and a second number all from user input, and have it print the result of the mathematical operation. The mathematical operations should be wrapped inside of functions.
int add(int a, int b) {return a + b;}
int subtract(int a, int b) {return a - b;}
int multiply(int a, int b) {return a * b;}
int divide(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }else return a / b;
}
int power(int a, int b) {return pow(a, b);}
int main(){
    cout << "Enter integer a _ b: ";
    int a,b; char op;
    cin >> a >> b;
    cout << "Enter operator (+, -, *, /, ^): ";
    cin >> op;
    switch (op) {
        case '+':
            cout << "Result: " << add(a, b) << endl;
            break;
        case '-':
            cout << "Result: " << subtract(a, b) << endl;
            break;
        case '*':
            cout << "Result: " << multiply(a, b) << endl;
            break;
        case '/':
            cout << "Result: " << divide(a, b) << endl;
            break;
        case '^':
            cout << "Result: " << power(a, b) << endl;
            break;
        default:
            cout << "Invalid entry.\n";
    }
    return 0;
}