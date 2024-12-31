#include<iostream>
using namespace std;
// Write a program in C++ to find the Greatest Common Divisor (GCD) of two numbers.
int GCD(int a, int b){
    int maxx=max(a,b), minn=min(a,b);
    for(int i=minn; i>0; i-=1){
        if(maxx%i==0 && minn%i==0){
            return i;
        }
    }
}
int main(){
    int a,b;
    cout << "Enter two numbers a & b: ";
    cin >> a >> b;
    cout << "GCD(a,b)=" << GCD(a,b);
    return 0;
}