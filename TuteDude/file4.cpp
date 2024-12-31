#include<iostream>
using namespace std;
// Write a program to Print all the duplicates in the input string.
void duplicates(string s){
    int count[256] = {0};
    for(int i = 0; i < s.length(); i++){
        count[s[i]]++;
    }
    cout << "Duplicates in the string are: ";
    for(int i = 0; i < 256; i++){
        if(count[i] > 1){
            cout << (char)i << " ";
        }
    }
}
int main(){
    string s;
    cout << "Enter a valid string: ";
    cin >> s;
    duplicates(s);
    return 0;
}