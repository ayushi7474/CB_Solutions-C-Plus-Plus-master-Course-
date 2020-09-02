/*You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

Input Format
First line contains integer t as number of test cases.
Each test case contains following input. First line contains integer n which represents the length of the data and next line contains n space separated integers denoting the elements for the BST.

Constraints
1 < t < 100
1< n < 1000

Output Format
For each testcase , print the preorder traversal of the BST in a new line.

Sample Input
1
7
1 2 3 4 5 6 7
Sample Output
4 2 1 3 6 5 7
Explanation
The tree looks like

             4
          /      \
       2           6
    /     \      /    \
   1       3    5      7
We print the preorder of the final tree.
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node* BST(int *arr, int start, int end) {
    if(start > end) {
        return NULL;
    }
    int mid = (start + end)/ 2;
    Node* root = new Node();
    root->data = arr[mid];
    root->left = BST(arr, start, mid - 1);
    root->right = BST(arr, mid+1, end );
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
int main() {
   int t;
   cin>>t;
   while(t--) {
       int n;
       cin>>n;
       int arr[n];
       for(int i = 0 ; i < n ; i ++) {
           cin>>arr[i];
       }
       Node* root = BST(arr, 0, n-1);
       PreOrder(root);
	   cout<<endl;
   }
   return 0;
}
