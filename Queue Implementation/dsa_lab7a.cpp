// EXPERIMENT 7a
// Write a program to implement Circular QUEUE using Array that performs following operations
// (a)	INSERT 
// (b)	DELETE 
// (c)	DISPLAY

#include<iostream>
using namespace std;

class Queue{
    int rear, front, size;
    int *queue;
public:
    Queue(int s){
        front=rear=-1;
        size=s;
        queue=new int[s];
    }
    void enQueue(int val){
	    if((front==0 && rear==size-1) || ((rear+1)%size==front)){
	    	cout << "\n***Condition of overflow***";
	    	return;
	    }else if(front==-1){ //Insert First Element
	    	front=rear=0;
	    	queue[rear]=val;
	    }else if(rear==size-1 && front!=0){
	    	rear=0;
	    	queue[rear]=val;
	    }else{
	    	rear=rear+1;
	    	queue[rear] = val;
	    }
        cout << "Successfully inserted!";
    }
	int deQueue(){
        if(front==-1){
		    cout << "\nQueue is Empty";
		    return 0;
	    }
	    int x = queue[front];
	    if(front==rear){
	    	front=-1;
	    	rear=-1;
	    }else if(front==size-1)
	    	front=0;
	    else
	    	front++;
	    return x;
    }
	void displayQueue(){
        if(front==-1){
		    cout << "\nQueue is Empty";
		    return;
	    }
	    cout << "\nElements in Circular Queue are: ";
	    if(rear>=front){
	    	for(int i=front; i<=rear; i++)
	    		cout << queue[i] << " ";
	    }else{
	    	for(int i=front; i<size; i++)
	    		cout << queue[i] << " ";
		    for(int i=0; i<=rear; i++)
		    	cout << queue[i] << " ";
	    }
        cout << endl;
    }
};
int main(){
    int size, choice;
    cout << "Enter the size of the circular queue: ";
    cin >> size;
	Queue q(size);
    while(true){
        cout << "\nMenu:\n"
             << "1. Insert elements in the queue.\n"
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