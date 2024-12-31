#include<iostream>
using namespace std;

// program in C++ to find the perfect numbers between 1 and 500

int perfectN(int n){
    int sum=0;
    while(n!=0){
        n=n/2;
        sum=sum+perfectN(n);
    }
    return sum;    
}
int main(){ 
    int n;
    cin >> n;
    cout << perfectN(n);
    return 0;
}