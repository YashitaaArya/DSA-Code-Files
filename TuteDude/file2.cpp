#include<iostream>
using namespace std;
// Write a program in C++ to find the perfect numbers between 1 and 500. 
bool isPerfectNo(int n){
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum = sum + i;
        }
    }
    if(sum==n) return true;
    return false;
}
int main(){
    cout << "The perfect Numbers between 1 to 500 are: ";
    for(int i=2; i<500; i++){
        if(isPerfectNo(i)==true){
            cout<<i<<" ";
        }
    }
    return 0;
}