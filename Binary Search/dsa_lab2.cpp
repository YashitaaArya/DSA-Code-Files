#include<iostream>
using namespace std;

// write a program to search an item in an array using binary search.
// If found, then delete that item in such a way that the resultant array must be sorted. 
// Write individual functions for binary search, insertion and deletion.

int binarySearch(int arr[], int n, int a){
    int first=0, last=n-1;
    while(first<=last){
        int mid = (first+last)/2;
        if(arr[mid]==a)
            return mid;
        else if(arr[mid]<a)
            first = mid+1;
        else
            last=mid-1;
    }
    return -1;
}
void insert(int arr[], int& n, int a){
    int i=n-1;
    while(i>=0 && arr[i]>a){
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=a;
    n++;
}
void deleteElement(int arr[], int& n, int a){
    int pos = binarySearch(arr, n, a);
    if(pos != -1){
        for (int i=pos; i<n-1; i++){
            arr[i]=arr[i+1];
        }
        n--;
    }else{
        cout << "Element doesn't exist!" << endl;
    }
}
int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: "<<endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    while(true){
        int searchItem;
        string ans1, ans2, ans3;
        cout << "Enter the element to be searched: ";
        cin >> searchItem;
        if(binarySearch(arr, n, searchItem)!=-1){
            cout << "Element found at "<< binarySearch(arr, n, searchItem)+1 << " position." << endl;
            cout << "Do you wish to delete the same element? (y/n)\n";
            cin >> ans1;
            if (ans1=="y"){
                deleteElement(arr, n, searchItem);
                cout << "Successfully deleted!" << endl;
                for (int i=0; i<n; i++){
                    cout << arr[i] << " ";
                }
            }else{
                cout << "Not deleted.\n";
            }
        }else{
            cout << "Element not found."<< endl;
            cout << "Do you wish to insert the same element? (y/n)\n";
            cin >> ans2;
            if (ans2=="y"){
                insert(arr, n, searchItem);
                cout << "Successfully inserted!" << endl;
                for (int i=0; i<n; i++){
                    cout << arr[i] << " ";
                }
            }else{
                cout << "Not inserted.\n";
            }
        }
        cout << "\nContinue the search? (yes/no)\n";
        cin >> ans3;
        if (ans3=="no"){
            return 0;
        }
    }
}
