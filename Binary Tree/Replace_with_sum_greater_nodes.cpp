/* Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. Include the current node's data also.

Input Format
The first line contains a number n showing the length of the inorder array of BST. The next line contains n integers denoting the elements of the array.

Constraints
2 ≤ N ≤ 10^3

Output Format
Print the preorder traversal of the new tree.

Sample Input
7
20 30 40 50 60 70 80
Sample Output
260 330 350 300 150 210 80
Explanation
The original tree looks like

            50             
        /        \                
      30          70
    /    \       /   \ 
  20    40      60    80
We are supposed to replace the elements by the sum of elements larger than it.
80 being the largest element remains unaffected .
70 being the second largest element gets updated to 150 (70+80)
60 becomes 210 (60 + 70 + 80)
50 becomes 260 (50 + 60 + 70 + 80)
40 becomes 300 (40 + 50 + 60 + 70 + 80)
30 becomes 330 (30 + 40 + 50 + 60 + 70 + 80)
20 becomes 350 (20 + 30 + 40 + 50 + 60 + 70 + 80)

The new tree looks like

           260             
        /        \                
     330         150
    /    \       /   \ 
  350    300   210    80
The Pre-Order traversal (Root->Left->Right) looks like :
260 330 350 300 150 210 80. */
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
void PreOrder(Node* root) {
    if(root == NULL) {
        return ;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
Node* BuildTree(int *ino, int start, int end) {
    if(start >  end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node* root = new Node();
    root->data = ino[mid];
    root->left = BuildTree(ino, start, mid-1);
    root->right = BuildTree(ino, mid+1, end);
    return root;
}
Node* Sums(Node* root, int *sum) {
    if(root == NULL) {
        return NULL;
    }
    Sums(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum;
    Sums(root->left, sum);
    return root;
}
void Sum(Node* root) {
   int sum = 0;
   Sums(root, &sum);

}
int main() {
   int n, i;
   cin>>n;
   int ino[n];
    for(i = 0 ; i < n ; i ++) {
        cin>>ino[i];
    }
    Node* root = BuildTree(ino,0,n-1);
    Sum(root);
    PreOrder(root);
    return 0;
}
