/* Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".

Input Format
A single integer N

Constraints
N <= 10^9

Output Format
Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet in increasing order.

Sample Input
3
Sample Output
4 5
*/
#include<iostream>
#include <cmath>
using namespace std;
int main() {

    int n;
    cin >> n;
    int sum=0;

    if(n==0||n==1||n==2||n<0) {
        cout << "-1";
        return 0;
    }

    long long int x,y;

long long int m;
    if(n%2==0) {
        m=n/2;
        n=1;
        
        x=pow(m,2)-pow(n,2);
        y=pow(m,2)+pow(n,2);
        cout << x << " " << y;

    }

    else {
        m=(n+1)/2;
        n=(n-1)/2;
        x=2*m*n;
        y=pow(m,2)+pow(n,2);

        cout << x << " " << y;
    }

	return 0;
}
