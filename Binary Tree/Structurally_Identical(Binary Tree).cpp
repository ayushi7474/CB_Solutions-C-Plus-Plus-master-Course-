/* Given two trees check if they are structurally identically. Structurally identical trees are trees that have same structure. They may or may not have the same data though.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
1 <= N <= 10^4

Output Format
Display the Boolean result

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
true
Explanation
The given two trees have the exact same structure and hence we print true.  */

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
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
bool isSymmetric(Node* p, Node* q) {
    if(p == NULL && q == NULL) {
        return true;
    }
    if(p == NULL || q == NULL) {
        return false;
    }
    return isSymmetric(p->left, q->left) && isSymmetric(p->right, q->right);
}
int main() {
    Node *p = BuildTree("true");
    Node *q = BuildTree("true");
    if(isSymmetric(p,q))
    cout<<"true";
    else
    cout<<"false";
    return 0;
}