#include<iostream>
using namespace std;
// write a program to check whether a given character is contained in a string or not and find its position
void checkposition(string s, char c){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == c){
            cout << "Character " << c << " found at position " << i+1 << endl;
        }
    }
}
int main(){
    string s;
    cout << "Enter the string to be parsed: ";
    cin >> s;
    char c;
    cout << "Enter the character to be searched: ";
    cin >> c;
    checkposition(s,c);
    return 0;
}