/* Given a binary tree , print the nodes in left to right manner as visible from below the tree

Input Format
Level order input for the binary tree will be given.

Constraints
No of nodes in the tree can be less than or equal to 10^7

Output Format
A single line containing space separated integers representing the bottom view of the tree

Sample Input
1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
Sample Output
4 2 6 3
Explanation
The tree looks like

             1
          /      \
       2           3
    /     \       /
   4       5     6
(Note that 5 and 6 are at the same position so we consider the right one to lower)

*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    int hd;
    Node *left, *right;
};
Node* buildTree() {
	int d;
    cin>>d;
    queue<Node *>q;
    Node *root=new Node();
    root->data = d;
    q.push(root);
    int c1,c2;
    while(!q.empty())
    {
        Node *f=q.front();
        q.pop();
        cin>>c1>>c2;
        if(c1!=-1)
        {
            f->left=new Node();
            f->left->data = c1;
            q.push(f->left);
        }
        if(c2!=-1)
        {
            f->right=new Node();
            f->right->data = c2;
            q.push(f->right);
        
         }
    }
    return root;
}
void BottomView(Node* root) {
    if(root == NULL) {
        return;
    }
    int hd = 0;
    map<int,int> m;
    queue<Node*> q;

    root->hd = hd;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        hd = temp->hd;
        m[hd] = temp->data;
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 


    }
    for(auto i = m.begin(); i != m.end() ; ++i)
    cout<<i->second<<" ";
}

int main() {
    Node* root = buildTree();
    BottomView(root);

    return 0;
}
