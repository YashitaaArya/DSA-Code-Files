// Experiment 4
/* Write a menu driven program to implement following operations on the singly linked list. 
Please make sure that all the functions are working for all the possible test cases.
(a) Insert a node at the front of the linked list.
(b) Insert a node at the end of the linked list.
(c) Insert a node at the given position in the link list.
(d) Delete first node of the linked list.
(e) Delete last node of the list.
(f) Delete a node from specified position.
(g) Display the elements of the link list. */

#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node* start = NULL;
void insert_at_beginning(int val){
    struct node* NN = new node;
    NN->data = val;
    NN->next = start;
    start = NN;
}
void delete_first(){
    struct node* ptr;
    if (start == NULL){
        cout << "List is empty" << endl;
        return;
    }else{
        ptr = start;
        start = start -> next;
        delete(ptr);
    }
}
void insert_at_end(int val){
    // struct node* start = NULL;
    struct node *NN = new node;
    struct node *ptr;
    NN->data = val;
    NN->next = NULL;
    if (start == NULL){
        start = NN;
    }else{
        ptr = start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = NN;
    }
}
void delete_last(){
    struct node* ptr;
    struct node* preptr;
    if (start == NULL){
        cout << "List is empty" << endl;
        return;
    }else{
        ptr = start;
        if (start -> next == NULL){
            start = NULL;
            delete(ptr);
        }else{
            preptr=ptr;
            while(ptr->next!=NULL){
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next = NULL;
            delete(ptr);
        }
    }
}
void delete_from_middle(int pos){
    if(start==NULL){
        cout << "List is empty" << endl;
        return;
    }
    struct node* ptr = start;
    struct node* preptr = NULL;
    int count = 1;
    while(ptr!=NULL && count!=pos){
        preptr=ptr;
        ptr=ptr->next;
        count++;
    }
    if(ptr==NULL){
        cout << "Position out of range" << endl;
        return;
    }
    if(preptr==NULL){
        start=ptr->next;
    }else{
        preptr->next=ptr->next;
    }
    delete ptr;
}
void insert_in_middle(int val, int pos){
    struct node *NN = new node;
    NN->data=val;
    if(start==NULL){
        start=NN;
        return;
    }
    if(pos==1){
        NN->next=start;
        start=NN;
        return;
    }
    struct node *ptr = start;
    struct node *preptr = NULL;
    int count=1;
    while(ptr!=NULL && count!=pos){
        preptr=ptr;
        ptr=ptr->next;
        count++;
    }
    if(ptr==NULL && count!=pos){
        cout << "Position out of range" << endl;
        delete NN;
        return;
    }
    preptr->next=NN;
    NN->next=ptr;
}
void display(){
    struct node *ptr;
    ptr=start;
    if(ptr==NULL){
        cout << "List is empty\n";
    }
    while(ptr!=NULL){
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
}
int main(){
    int choice;
    while (true){
        cout << endl;
        cout << "MENU:" << endl;
        cout << "Enter the operation to be performed: " << endl
         << "1. Insert a node at the front of the linked list." << endl
         << "2. Insert a node at the end of the linked list." << endl
         << "3. Insert a node at the given position in the link list." << endl
         << "4. Delete first node of the linked list." << endl
         << "5. Delete last node of the list." << endl
         << "6. Delete a node from specified position." << endl
         << "7. Display the elements of the link list." << endl
         << "8. Exit the program." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl;
            int val;
            cout << "Enter the value to be inserted: ";
            cin >> val;
            insert_at_beginning(val);
            cout << "Successfully inserted." << endl;
            break;
        case 2:
            cout << endl;
            cout << "Enter the value to be inserted: ";
            cin >> val;
            insert_at_end(val);
            cout << "Successfully inserted." << endl;
            break;
        case 3:
            cout << endl;
            int pos;
            cout << "Enter the value to be inserted: ";
            cin >> val;
            cout << "Enter the position where node is to be inserted: ";
            cin >> pos;
            insert_in_middle(val, pos);
            cout << "Successfully inserted." << endl;
            break;
        case 4:
            cout << endl;
            delete_first();
            cout << "Successfully deleted." << endl;
            break;
        case 5:
            cout << endl;
            delete_last();
            cout << "Successfully deleted." << endl;
            break;
        case 6:
            cout << endl;
            cout << "Enter the position where node is to be deleted: ";
            cin >> pos;
            delete_from_middle(pos);
            cout << "Successfully deleted." << endl;
            break;
        case 7:
            cout << endl;
            display();
            break;
        case 8:
            cout << "Exiting program.\n";
            return 0;
            break;
        default:
            cout << "Invalid choice entered." << endl;
            break;
        }
    }  
    return 0;
}