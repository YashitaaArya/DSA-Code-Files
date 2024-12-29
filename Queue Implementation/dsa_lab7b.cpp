// EXPERIMENT 7b
// Write a program to implement QUEUE using Linked List that performs following operations
// (a)	INSERT 
// (b)	DELETE 
// (c)	DISPLAY

#include<iostream>
using namespace std;

struct QNode{
    int data;
    QNode* next;
    QNode(int d){
        data=d;
        next=NULL;
    }
};
class Queue{
    QNode *front, *rear;
public:
    Queue(){
        front=rear=NULL;
    }
    void enQueue(int x){
        QNode* NN=new QNode(x);
        if(front==NULL){
            front=rear=NN;
            return;
        }
        rear->next=NN;
        rear=NN;
    }
    int deQueue(){
        if(front==NULL){
            cout << "Empty queue!" << endl;
            return -1;
        }
        int x=front->data;
        QNode* ptr=front;
        if(front==rear){
            front=rear=NULL;
        }else
            front=front->next;
        delete(ptr);
        return x;
    }
    void displayQueue(){
        QNode* ptr;
        ptr=front;
        if(ptr==NULL){
            cout << "Queue is empty\n";
            return;
        }
        while(ptr!=NULL){
            cout << ptr->data << " ";
            ptr=ptr->next;
        }
    }
};
int main(){
    int choice;
	Queue q;
    while(true){
        cout << "\nMenu:\n"
             << "1. Insert elements in a queue.\n"
             << "2. Delete an element.\n"
             << "3. Display all the elements from the queue.\n"
             << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                int val;
                cout << "Enter the value to be inserted into the queue: ";
                cin >> val;
                q.enQueue(val);
                cout << "Successfully inserted!\n";
                break;
            case 2:
                cout << q.deQueue() << " DELETED!\n";
                break;
            case 3:
                cout << "Queue elements are: ";
                q.displayQueue();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice entered. Try again!\n";
                break;
        }
    }
}