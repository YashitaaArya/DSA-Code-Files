#include<iostream>
using namespace std;
// A person is eligible to vote if his/her age is greater than or equal to 18. Define a function to find out if he/she is eligible to vote
bool eligible(int x){
    if(x>=18) return true;
    return false;
}
int main(){
    cout << "Enter your age: ";
    int age;
    cin >> age;
    if(eligible(age)==true){
        cout << "You are eligible to vote.\n";
    }else{cout << "You're not eligible to vote.\n";}
    return 0;
}