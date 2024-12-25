// Experiment 3 //
// Implement following sorting algorithms to sort an array (make a dynamic array):
// 1.	Write a function to sort an array using Bubble sort. Use 1-bit variable FLAG to signal when no interchange take place during pass. 
//      If FLAG is 0 after any pass, then list is already sorted and there is no need to continue.
// 2.	Write a function to sort an array using Selection sort.
// 3.	Write a function to sort an array using Insertion sort.
// Write a menu driven program to implement above sorting. 
// Discuss Best, Average and Worst case time complexity of each sorting algorithm implemented above.

#include<iostream>
using namespace std;
void bubble_sort(int arr[], int n){
    cout << "Enter the elements for array :" << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;
    int FLAG;
    for (int j=0; j<n; j++){
        FLAG=0;
        for (int i=0; i<n-j; i++){
            if (arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                FLAG=1;
            }
        }
        if (FLAG==0){
            break;
        }
    }
}
void selection_sort(int arr[], int n){
    cout << "Enter the elements for array :" << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;
    int min;
    for (int j=0; j<n-1; j++){
        min=j;
        for (int i=j+1; i<n; i++){
            if(arr[min]>arr[i]){
                min = i;
            }
        }
        swap(arr[min],arr[j]);
    }
}
void insertion_sort(int arr[], int n){
    cout << "Enter the elements for array :" << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;
    int key;
    for (int j=1; j<n; j++){
        key=arr[j];
        int i = j-1;
        while(i>=0 && key<arr[i]){
            arr[i+1]=arr[i];
            i-=1;
        }
        arr[i+1]=key;
    }
}
int main(){
    int n, choice;
    cout << "Enter the size of array: ";
    cin >> n;
    int *arr= new int[n];
    while(true){
        cout << "\nEnter the function you wish to perform :" << endl
             << "1. Bubble sorting" << endl
             << "2. Selection sorting" << endl
             << "3. Insertion sorting" << endl
             << "4. Exit" << endl;
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Bubble sorting : " << endl;
                bubble_sort(arr,n);
                for (int i=0; i<n; i++){
                    cout << arr[i] << " ";
                }
                break;
            case 2:
                cout << "Selection sorting : " << endl;
                selection_sort(arr,n);
                for (int i=0; i<n; i++){
                    cout << arr[i] << " ";
                }
                break;
            case 3:
                cout << "Insertion sorting : " << endl;
                insertion_sort(arr,n);
                for (int i=0; i<n; i++){
                    cout << arr[i] << " ";
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;    
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}