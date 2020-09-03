/* Two elements of a binary search tree (BST) are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.

Input Format
First line contains n denoting the input size.
Next line contains n space separated integers denoting the preorder input of the tree.

NOTE : -1 indicates that the node does not exist.

Constraints
1 <= n <= 10^5
Your recovery algorithm should work in O(n) time.

Output Format
Print the two integers in space separated manner. The output should be sorted.

Sample Input
3 2 1 -1 -1 -1 5 6 4 -1 -1 -1 -1 
Sample Output
5 6
Explanation
The tree looks like

             3
          /      \
       2           5
    /            /    
   1           6      
             /
           4  
Swapping 5 and 6 makes the tree a BST. */
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node* BuildTree() {
    int d;
    cin>>d;
    if(d == -1) {
        return NULL;
    }
    Node* root = new Node();
    root->data = d;
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}
void Traverse(Node* root, vector<int> &val) {
    if(root == NULL) {
        return;
    }
    Traverse(root->left, val);
    val.push_back(root->data);
    Traverse(root->right, val);
}
int main() {
    Node* root = BuildTree();
     vector<int> val;
    Traverse(root, val);
    int x = -1, y = -1; //The two nodes may or may not be adjacent
    for(int i = 0 ; i < val.size() - 1 ; i ++) {
        if(val[i] > val[i+1]) {
            y = val[i+1];
            if(x == -1) 
                x = val[i];
                else 
                break;     
        }
    }
    cout<<min(x,y)<<" "<<max(x,y);
    return 0;
}


