// Experiment 5
// II.	Write a program to implement STACK using Linked List that performs following operations
// (a)	PUSH
// (b)	POP
// (c)	PEEP
// (d)	DISPLAY
#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node* top = NULL;
void pushVal(int val){
    struct node* NN = new node;
    NN->data = val;
    NN->next = top;
    top = NN;
}
void popOut(){
    struct node* ptr;
    if (top == NULL){
        cout << "Stack is empty" << endl;
        return;
    }else{
        ptr = top;
        int x = ptr -> data;
        top = top -> next;
        delete(ptr);
        cout << x << " deleted.\n";
    }
}
void peepInto(){
    struct node* ptr;
    if (top == NULL){
        cout << "Stack is empty" << endl;
        return;
    }else{
        ptr = top;
        int x = ptr -> data;
        cout << "Top: " << x <<endl;
    }
}
void display(){
    struct node* ptr;
    if (top == NULL){
        cout << "Stack is empty" << endl;
        return;
    }else{
        ptr = top;
        while(ptr!=NULL){
            cout << ptr -> data << endl;
            ptr = ptr->next;
        }
        return;
    }
}
int main(){
    int choice;
    while(true){
        cout << "\nMenu:\n";
        cout << "1. Push a value in stack\n";
        cout << "2. Pop from stack\n";
        cout << "3. Peep into the stack\n";
        cout << "4. Display all the elements from the stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                int val;
                cout << "Enter the value to be pushed into stack: ";
                cin >> val;
                pushVal(val);
                cout << "Value pushed in!\n";
                break;
            case 2:
                popOut();
                break;
            case 3:
                peepInto();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice entered. Try again!\n";
                break;
        }
    }
    return 0;
}