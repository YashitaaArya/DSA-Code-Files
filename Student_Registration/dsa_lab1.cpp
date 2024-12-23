// Experiment 1
// Create a structure for student which should contain fields like roll No., name, CGPI, semester. 
// Create an array of structure student to store this information about 10 students. Write individual functions to perform the following task: 
// (a)	Insert a new record of student at kth position (value of k will be entered by the user at run time). 
// (b)	Display the record of all students.
// (c)	Display records of all students having CGPI greater than k (value of k will be entered by the user at run time). 
// Write a menu-driven program to implement above operations.

#include <iostream>
using namespace std;
struct Student{
    int rollNo;
    string name;
    float CGPI;
    int semester;
};
Student students[10];
int numStudents = 0;
void insertRecord(int k) {
    if (numStudents < 10) {
        cout << "Enter details for student " << k << ":\n";
        cout << "Roll No.: ";
        cin >> students[k - 1].rollNo;
        cout << "Name: ";
        cin >> students[k - 1].name;
        cout << "CGPI: ";
        cin >> students[k - 1].CGPI;
        cout << "Semester: ";
        cin >> students[k - 1].semester;
        cout << "Record inserted successfully.\n";
    } else {
        cout << "Array is full. Cannot insert more records.\n";
    }
    numStudents++;
}
void displayAllRecords() {
    cout << "Student Records:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Roll No.: " << students[i].rollNo << ", Name: " << students[i].name << ", CGPI: " << students[i].CGPI << ", Semester: " << students[i].semester << endl;
    }
}
void displayRecordsByCGPI(float k) {
    cout << "Student Records with CGPI > " << k << ":\n";
    for (int i = 0; i < numStudents; i++) {
        if (students[i].CGPI > k) {
            cout << "Roll No.: " << students[i].rollNo << ", Name: " << students[i].name << ", CGPI: " << students[i].CGPI << ", Semester: " << students[i].semester << endl;
        }
    }
    cout << "No other value exists" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a new record\n";
        cout << "2. Display records of all students\n";
        cout << "3. Display records of students with CGPI greater than a specified value\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int k;
                cout << "Enter the position to insert the new record: ";
                cin >> k;
                insertRecord(k);
                // numStudents++;
            
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                float cgpiThreshold;
                cout << "Enter the CGPI threshold: ";
                cin >> cgpiThreshold;
                displayRecordsByCGPI(cgpiThreshold);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}