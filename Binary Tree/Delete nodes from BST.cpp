/* You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree. It is assured that the elements of array A2 will be present in the tree.
Note : In case of node with 2 children, consider its inorder successor as its replacement.

Input Format
First line contains integer t as number of test cases.
Each test case contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers denoting the elements of array A1. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers denoting the elements of array A2.

Constraints
1 < t < 100
1< n,m < 1000

Output Format
Print the preorder traversal of the final resultant tree.

Sample Input
1
7
5 3 2 4 7 6 8
3
2 3 5
Sample Output
6 4 7 8 
Explanation
Initially the tree looks like

             5
          /      \
       3           7
    /     \      /    \
   2       4    6      8
After the deletion , the tree looks like

               6
            /     \
           4       7
                     \
                      8
We print the preorder of the final tree.
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node* Insert(Node* root, int d) {
    if(root == NULL) {
    Node* roott = new Node();
    roott->data = d;
    return roott; }
    if(d <= root->data) {
        root->left = Insert(root->left, d);
    }
    else {
        root->right = Insert(root->right, d);
    }
    return root;
}
Node* BuildTree(Node* root, int *arr, int size) {
  
    for(int i = 1 ; i < size ; i ++) {
        root = Insert(root, arr[i]);
    }
    return root;
}
void PreOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
Node* Delete_Node(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if( key < root->data) {
        root->left = Delete_Node(root->left, key);
        return root;
    }
    if(key > root->data) {
        root->right = Delete_Node(root->right, key);
        return root;
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left==NULL && root->right!=NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right==NULL && root->left!=NULL) {
            Node* temp = root->left;
            delete root;
            return temp; }
          else {
              Node* replace = root->right;
              while(replace->left != NULL) {
                  replace = replace->left;
              }
              root->data = replace->data;
              root->right = Delete_Node(root->right, replace->data);
              return root;
          }  
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, i;
        cin>>n;
        int arr[n];
        for(i = 0 ; i < n ; i ++) {
            cin>>arr[i];
        }
       
        Node* root=new Node();
        root->data = arr[0];
		root = BuildTree(root,arr,n);
     int m, d;
        cin>>m;
        
        for(i = 0 ; i < m ; i ++) {
            cin>>d;
           root =  Delete_Node(root, d);
        }
       

       PreOrder(root);
cout<<endl;
    }
    return 0;
}