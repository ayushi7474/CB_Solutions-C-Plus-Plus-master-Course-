/*Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

Input Format
Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.

Constraints
1 <= Nodes in tree <=1000
1<K<10

Output Format
A single line containing the sum at level K.

Sample Input
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2
Sample Output
20
Explanation
Here the tree looks like

                     1                                 Level 0
                /          \
              2              5                         Level 1
           /      \       /     \
          3       4      6        7                    Level 2
Sum at Level 2 = 3 + 4 + 6 + 7 = 20
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
static int sum = 0;
Node* Buildtree()
{
	int d, c;
	cin>>d>>c;
	Node* root = new Node();
    root->data = d;
	if(c == 1 ) {
		root->left = Buildtree();
	}
	if(c == 2) {
		root->left = Buildtree();
		root->right = Buildtree();
	} 
	return root;
}
void sumLevelK(Node* root, int k) {
	if(root == NULL) {
		return ;
	}
	
	if(k == 0) {
		sum = sum + root->data;
		
	}
	sumLevelK(root->left, k-1);
	sumLevelK(root->right, k-1);
}
void BFS(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())  //For newline for each Level
    {
        Node* f = q.front();
        if(f == NULL) {
            cout<<endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
        cout<<f->data<<",";
        q.pop();
        if(f->left != NULL) { q.push(f->left); }
        if(f->right != NULL) { q.push(f->right); }
    }
    }

}
int main() {
	Node* root = Buildtree();
    
	int k;
	cin>>k;
	sumLevelK(root, k);
	cout<<sum;
	return 0;
}
