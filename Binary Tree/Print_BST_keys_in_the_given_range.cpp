/* You are given an array of integers. First of all , You have to form a binary search tree from given integers. Now you have provided two integers k1 and k2. You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).

Input Format
First line contains integer t as number of test cases. Each test case contains three lines. First line contains an integer n which is length of the array and second line contains n space separated integer. Third line contains the value of k1 and k2.

Constraints
1 < t < 20
1 < n < 50

Output Format
For each test case you have to print preorder traversal of the tree first and then print all nodes within the range k1 and k2 (inclusive). Refer to the sample testcase for exact output format.

Sample Input
1
5
4 3 2 5 6
3 5
Sample Output
# Preorder : 4 3 2 5 6 
# Nodes within range are : 3 4 5 
Explanation
The tree looks like

             4
          /      \
       3           5
    /                \
   2                  6
The nodes between the range 3 to 5 are 3,4,5.
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
Node* Buildtree(Node* root, int d) {
    if(root == NULL) {
    Node* temp = new Node();
    temp->data = d;
    temp->left = temp->right = NULL;
    root = temp;
    return root;
    }
    if(root->data < d) {
        root->right = Buildtree(root->right,d);
    }
    else {
        root->left = Buildtree(root->left, d);
    }
    return root;
}
void PrintRange(Node* root, int k1, int k2) {
    if(root == NULL) {
        return;
    }
    PrintRange(root->left, k1, k2);  //BECAUSE, order maintain karna hai
    if(root->data >= k1 && root->data <= k2) {
        cout<<root->data<<" ";
    }
    
        PrintRange(root->right, k1, k2);
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
        int n, ele;
        cin>>n;
         Node* root = NULL;
        for(int i = 0 ; i < n ; i ++) {
            cin >> ele;
            root = Buildtree(root, ele);
        }
        int k1, k2;
        cin>>k1>>k2;
        cout<<"# Preorder : ";
        PreOrder(root);
        cout<<endl;
        cout<<"# Nodes within range are : ";
        PrintRange(root, k1,k2);
        cout<<endl;
        
    }
	return 0;
}