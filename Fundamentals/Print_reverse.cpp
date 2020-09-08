/* Take N as input, Calculate it's reverse also Print the reverse.

Input Format
Constraints
0 <= N <= 1000000000

Output Format
Sample Input
123456789
Sample Output
987654321
Explanation
You've to calculate the reverse in a number, not just print the reverse.
*/
#include<iostream>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    int k;

    while(n!=0) {
        k=n%10;
        n=n/10;
        cout << k;
    }

	return 0;
}