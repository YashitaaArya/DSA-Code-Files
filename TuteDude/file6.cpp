#include<iostream>
using namespace std;
// Write a program to count the number of vowels and consonants in a String
void count(string s){
    int vowelcount=0, consonantcount=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || 
        s[i]=='O' || s[i]=='U'){
            vowelcount++;
        }else{consonantcount++;}
    }
    cout << "Number of vowels: " << vowelcount 
         << "\nNumber of consonants: " << consonantcount;
}
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    count(s);
    return 0;
}