// EXPERIMENT 8
// Write a menu driven program to implement BST and write the functions to perform the following operations:
// 1. Insert an element.
// 2. Inorder traversal of tree
// 3. Preorder Traversal of tree
// 4. Postorder traversal of tree
// 5. Delete a node which can have two/one/no children.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* TREE = nullptr;
struct node* insertNode(struct node* root, int val){
    if (root == nullptr) {
        struct node* NN = new node;
        NN->data = val;
        NN->left = nullptr;
        NN->right = nullptr;
        return NN;
    }
    if(val < root->data){
        root->left = insertNode(root->left, val);
    }else{
        root->right = insertNode(root->right, val);
    }
    return root;
}
struct node* findMinNode(struct node* root){
    struct node* current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}
struct node* deleteNode(struct node* root, int val){
    if(root == nullptr){
        return nullptr;
    }else if(val < root->data){
        root->left = deleteNode(root->left, val);
    }else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }else{
        // Case 1: No child or only one child
        if (root->left == nullptr) {
            struct node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 2: Node with two children
        struct node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void displayINORDER(struct node* root) {
    if (root != nullptr) {
        displayINORDER(root->left);
        cout << root->data << " ";
        displayINORDER(root->right);
    }
}
void displayPREORDER(struct node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        displayPREORDER(root->left);
        displayPREORDER(root->right);
    }
}
void displayPOSTORDER(struct node* root) {
    if (root != nullptr) {
        displayPOSTORDER(root->left);
        displayPOSTORDER(root->right);
        cout << root->data << " ";
    }
}
int main() {
    int choice;
    while (true) {
        cout << endl;
        cout << "MENU:" << endl;
        cout << "Enter the operation to be performed: " << endl
            << "1. Insert an element in the tree." << endl
            << "2. Inorder traversal of tree." << endl
            << "3. Preorder Traversal of tree" << endl
            << "4. Postorder traversal of tree" << endl
            << "5. Delete any node." << endl
            << "6. Exit the program." << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << endl;
            int val;
            cout << "Enter the value to be inserted: ";
            cin >> val;
            TREE = insertNode(TREE, val);
            cout << "Successfully inserted." << endl;
            break;
        case 2:
            cout << endl;
            cout << "Inorder traversal is: ";
            displayINORDER(TREE);
            cout << endl;
            break;
        case 3:
            cout << endl;
            cout << "Preorder traversal is: ";
            displayPREORDER(TREE);
            cout << endl;
            break;
        case 4:
            cout << endl;
            cout << "Postorder traversal is: ";
            displayPOSTORDER(TREE);
            cout << endl;
            break;
        case 5:
            cout << endl;
            int deleteVal;
            cout << "Enter the value to be deleted: ";
            cin >> deleteVal;
            TREE = deleteNode(TREE, deleteVal);
            cout << "Successfully deleted." << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice entered." << endl;
            break;
        }
    }
    return 0;
}