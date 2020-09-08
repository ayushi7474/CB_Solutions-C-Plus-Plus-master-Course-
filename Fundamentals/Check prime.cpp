/* Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".

Input Format
Constraints
2 < N <= 1000000000

Output Format
Sample Input
3
Sample Output
Prime
Explanation
The output is case specific
*/
#include<iostream>
#include <cmath>
using namespace std;
int main() {
    long long int n,k=0,i;
    cin >> n;
    for (i=2;i<=sqrt(n);i++) {
        if(n%i==0) {
            cout << "Not Prime";
            k=0;
            break;
        }
        else
        k=1;

    }
    if(k==1 || n==2 || n==3)
    cout << "Prime";

	return 0;
}