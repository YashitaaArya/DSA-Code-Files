#include<iostream>
using namespace std;

// find the largest difference among the elements of a circular link list.
// find the Nth node from the end of a singly linked list and return data if exists or -1 if doesn't.

struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insertion_circular(int val){
    struct node *NN= new node;
    NN->data=val;
    if(start==NULL){
        start=NN;
        NN->next=start;
    }else{
        NN->next=start;
        node *ptr=start;
        while(ptr->next!=start){
            ptr=ptr->next;
        }
        ptr->next=NN;
    }
}
void insertion_singly(int val){
    struct node *NN= new node;
    NN->data=val;
    if(start==NULL){
        start=NN;
        NN->next=NULL;
    }else{
        NN->next=NULL;
        node *ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=NN;
    }
}
void display_circular(){
    if(start==NULL){
        cout << "List is empty\n";
    }else{
        node *ptr=start;
        while(ptr->next!=start){
            cout << ptr->data << " ";
            ptr=ptr->next;
        }
        cout << ptr->data << endl;
    }
}
void display_singly(){
    if(start==NULL){
        cout << "List is empty\n";
    }else{
        node *ptr=start;
        while(ptr->next!=NULL){
            cout << ptr->data << " ";
            ptr=ptr->next;
        }
        cout << ptr->data << endl;
    }
}
void nth_node(int n){
    node *ptr=start;
    int count=0;
    while(ptr!=NULL){
        count+=1;
        ptr=ptr->next;
    }
    ptr=start;
    if(n>count){
        cout << -1 << endl;
    }else{
        for(int i=1; i<=count-n; i++){
            ptr=ptr->next;
        }
        cout << ptr->data << endl;
    }
}
void difference(){
    node *ptr=start;
    int max=ptr->data;
    int min=ptr->data;
    while(ptr->next!=start){
        ptr=ptr->next;
        if(ptr->data>max){
            max=ptr->data;
        }
        if(ptr->data<min){
            min=ptr->data;
        }
    }
    cout << "Difference between max and min values: " << max-min << endl;
}
int main(){
    while(true){
        cout << "MENU:\n"
             << "1. Insert in circular Linked list.\n"
             << "2. Display all elements of circular LL.\n"
             << "3. Finding largest difference.\n"
             << "4. Insert in singly Linked list.\n"
             << "5. Display all elements of singly LL.\n"
             << "6. Finding nth node.\n"
             << "7. Exit.\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            int val;
            cin >> val;
            insertion_circular(val);
            cout << endl;
            break;
        case 2:
            cout << "Elements in the linked list : ";
            display_circular();
            cout << endl;
            break;        
        case 3:
            cout << endl;
            difference();
            break;
        case 4:
            cout << "Enter the value to be inserted: ";
            cin >> val;
            insertion_singly(val);
            cout << endl;
            break;
        case 5:
            cout << "Elements in the linked list : ";
            display_singly();
            cout << endl;
            break;        
        case 6:
            cout << "Enter the value of n for the Nth node from end : ";
            int n;
            cin >> n;
            nth_node(n);
            cout << endl;
            break;         
        case 7:
            cout << "Exiting program\n";
            return 0;       
        default:
            cout << "Please enter the valid choice.\n";
            break;
        }
    }
    return 0;
}