/* Given a Binary tree check if it is balanced i.e. depth of the left and right sub-trees of every node differ by 1 or less.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
1 <= No of nodes <= 10^5

Output Format
Display the Boolean result

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
true
Explanation
The tree looks like

             10
          /       \
       20           30
    /     \       /     \
   40      50    60      73
The given tree is clearly balanced as depths of the left and right sub-trees of every node differ by 1 or less.
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
struct Balance {
    bool balance;
    int height;
};
Node* BuildTree(string str) {
    if(str == "true") {
    int d;
    cin>>d;
    Node* temp = new Node();
    temp->data = d;
    string ans;
    cin>>ans;
    if(ans == "true")
    temp->left = BuildTree(ans);
    cin>>ans;
    if(ans == "true")
    temp->right = BuildTree(ans);
    return temp;
    }
    return NULL;
}
Balance isBalanced(Node* root) {
   Balance b;
   if(root == NULL) {
       b.balance = true;
       b.height = 0;
       return b;
   }
   Balance left_tree = isBalanced(root->left);
   Balance right_tree = isBalanced(root->right);

     b.height = max(left_tree.height, right_tree.height) + 1;

   if((abs(left_tree.height - right_tree.height) <= 1)  && left_tree.balance && right_tree.balance) {
       b.balance = true;
   }
   else {
       b.balance = false;
   }
   return b;
        }
int main() {
    Node *root = BuildTree("true");
    Balance ans = isBalanced(root);
    if(ans.balance)
    cout<<"true";
    else
    cout<<"false";
    return 0;
}