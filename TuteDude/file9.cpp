#include<iostream>
using namespace std;
// Write a program that ask for two numbers, compare them and show the maximum. Declare a function called max_two that compares the numbers and returns the maximum
int max_two(int a, int b) {
    if(a>b) return a;
    else return b;
}
int main(){
    cout << "Enter first number: ";
    int a,b;
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "The maximum number is: " << max_two(a,b) << endl;
    return 0;
}