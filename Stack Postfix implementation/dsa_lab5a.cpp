// Experiment 5
// I.	Write a program to implement STACK using arrays that performs following operations
// (a)	PUSH
// (b)	POP
// (c)	PEEP
// (d)	DISPLAY

#include<iostream>
using namespace std;
int top=-1;
void push(char stack[], int &top, int size, char val){
    if(top==size-1){
        cout << "Condition of Overflow\n";
        return;
    }else{
        top=top+1;
        stack[top]=val;
    }
}
void pop(char stack[], int &top){
    if (top==-1){
        cout << "Condition of Underflow\n";
        return;
    }else{
        top=top-1;
        return;
    }
}
// int peep(char stack[], int top){
//     if (top==-1){
//         cout << "Condition of Underflow\n";
//         return 0;
//     }else{
//         cout << "Value at the top of stack: ";
//         int x=stack[top];
//         cout << x << endl;
//         return 0;
//     }
// }
void pushVal(int stack[], int size, int val){
    if(top==size-1){
        cout << "Condition of Overflow\n";
        return;
    }else{
        top=top+1;
        stack[top]=val;
        cout << val << " is pushed in.\n";
        return;
    }
}
int popOut(int stack[]){
    if (top==-1){
        cout << "Condition of Underflow\n";
        return 0;
    }else{
        int x=stack[top];
        top=top-1;
        cout << x << " is popped out.\n";
        return x;
    }
}
int peepInto(int stack[]){
    if (top==-1){
        cout << "Condition of Underflow\n";
        return 0;
    }else{
        cout << "Value at the top of stack: ";
        int x=stack[top];
        cout << x << endl;
        return 0;
    }
}
void display(int stack[], int size){
    if (top==-1){
        cout << "Stack is empty.\n";
        return;
    }else{
        cout << "Values in the stack: \n";
        for(int i=top; i>=0; i--){
            cout << stack[i] << endl;
        }
        return;
    }
}
// int main(){
//     int size, choice;
//     cout << "Enter the size of array: ";
//     cin >> size;
//     int stack[size];
//     while(true){
//         cout << "\nMenu:\n";
//         cout << "1. Push a value in stack\n";
//         cout << "2. Pop from stack\n";
//         cout << "3. Peep into the stack\n";
//         cout << "4. Display all the elements from the stack\n";
//         cout << "5. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice){
//             case 1:
//                 int val;
//                 cout << "Enter the value to be pushed into stack: ";
//                 cin >> val;
//                 pushVal(stack, size, val);
//                 break;
//             case 2:
//                 popOut(stack, size);
//                 break;
//             case 3:
//                 peepInto(stack, size);
//                 break;
//             case 4:
//                 display(stack, size);
//                 break;
//             case 5:
//                 cout << "Exiting program.\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice entered. Try again!\n";
//                 break;
//         }
//     }
// }