/* Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
None

Output Format
Display the values in zigzag level order in which each value is separated by a space

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
10 30 20 40 50 60 73 
*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node* BuildTree(string str) {
    if(str == "true") {
        int d;
        cin>>d;
        Node* root = new Node();
        root->data = d;
        string ans ; 
        cin>>ans;
        if(ans == "true") {
            root->left = BuildTree(ans);
        }
        cin>>ans;
         if(ans == "true") {
            root->right = BuildTree(ans);
        }
        return root;
    }
    return NULL;
}
int Height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int left_h = Height(root->left);
    int right_h = Height(root->right);
    return max(left_h, right_h) + 1;
}
void printRightLevel(Node* root, int k) {
     if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
   
    printRightLevel(root->right,k-1);
     printRightLevel(root->left,k-1);
}
void printLeftLevel(Node* root, int k) {
     if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    
    printLeftLevel(root->left,k-1);
    printLeftLevel(root->right,k-1);
}
void ZigZag(Node* root) {
    int h = Height(root);
    for(int i = 0 ; i < h ; i ++) {
        if(i % 2 == 0) {
            printLeftLevel(root, i);
        }
        if(i % 2 != 0) {
            
            printRightLevel(root, i);
        }
    }
}
int main() {
    Node* root = BuildTree("true");
    ZigZag(root);
    return 0;
}
