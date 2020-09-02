/* Given a binary tree , print its nodes from root to bottom as visible from right side of tree

Input Format
Level order input for the binary tree will be given.

Constraints
No of nodes in the tree can be less than or equal to 10^7

Output Format
A single line containing space separated integers representing the right view of the tree

Sample Input
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
Sample Output
1 3 6
Explanation
The tree looks like

             1
          /      \
       2           3
    /     \           \
   4       5           6
When viewed from the left , we would see the nodes 1,3 and 6.
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
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
void LeftView(Node* root, int level, int &maxlevel) {
	if(root == NULL) {
		return;
	}
	if(maxlevel < level) {
		cout<<root->data<<" ";
		maxlevel = level;
	}

	
	LeftView(root->right, level + 1, maxlevel);
	LeftView(root->left, level + 1, maxlevel);
}
int main() {
	Node* root = buildTree();
	int maxlevel = -1;
	LeftView(root, 0, maxlevel);
	return 0;
}