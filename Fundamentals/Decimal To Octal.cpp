/* Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.

Input Format
Constraints
0 < N <= 1000000000

Output Format
Sample Input
63
Sample Output
77
Explanation
Both input and output are integers
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n,p,i,sum,o[100];
    
    cin >> n;
    for(i=0;n!=0;i++) {
        o[i]=n%8;
        n=n/8;
        
    }
    
    for(i>=0;i--;){
        cout << o[i];
    }

	return 0;
}