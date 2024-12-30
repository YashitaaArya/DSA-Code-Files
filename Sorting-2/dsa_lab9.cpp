// EXPERIMENT 9
// Write a program to implement MergeSort and QuickSort.

#include<iostream>
using namespace std;
void Merge(int A[], int p, int q, int r) {
    int n1=q-p+1;
    int n2=r-q;
    int L[n1], R[n2];
    for (int i=0; i<n1; i++)
        L[i]=A[p+i];
    for (int j=0; j<n2; j++)
        R[j]=A[q+1+j];
    int i=0,j=0,k=p;  
    while (i<n1 && j<n2){
        if (L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
        k++;
    }    
    while (i<n1) {
        A[k]=L[i];
        i++;
        k++;
    }    
    while (j<n2) {
        A[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int A[], int p, int r){
    if(p<r){
        int q=(p+r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}
int partition(int A[], int p, int r){
    int pivot=A[r];
    int i=p-1;
    for(int j=p; j<r; j++){
        if (A[j]<=pivot){
            i=i+1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}
void QuickSort(int A[], int p, int r){
    if(p<r){
        int q=partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}
int main(){
    int choice;
    cout << "Enter the size of array: ";
    int size;
    cin >> size;
    int A[size];
    while(true){
        cout << endl << "\nChoose anyone option: \n"
             << "1. Sort the array using MergeSort.\n"
             << "2. Sort the array using QuickSort.\n"
             << "3. Exit.\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the elements: ";
                for(int i=0; i<size; i++){
                    cin >> A[i];
                }
                MergeSort(A, 0, size-1);
                cout << "\nArray after MergeSort is: ";
                for (int i=0; i<size; i++){
                    cout << A[i] << " ";
                }
                break;
            case 2:
                cout << "Enter the elements: ";
                for(int i=0; i<size; i++){
                    cin >> A[i];
                }
                QuickSort(A, 0, size-1);
                cout << "\nArray after QuickSort is: ";
                for (int i=0; i<size; i++){
                    cout << A[i] << " ";
                }
                break;
            case 3:
                cout << "Exiting program!\n";
                return 0;
            default:
                cout << "Invalid choice entered!\n";
                break;                
        }
    }    
    return 0;
}