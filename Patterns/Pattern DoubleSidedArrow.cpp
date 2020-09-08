/* Take N as input. For a value of N=7, we wish to draw the following pattern :

                            1 
                        2 1   1 2 
                    3 2 1       1 2 3 
                4 3 2 1           1 2 3 4 
                    3 2 1       1 2 3 
                        2 1   1 2 
                            1 
Input Format
Take N as input.

Constraints
N is odd number.

Output Format
Pattern should be printed with a space between every two values.

Sample Input
7
Sample Output
            1 
        2 1   1 2 
    3 2 1       1 2 3 
4 3 2 1           1 2 3 4 
    3 2 1       1 2 3 
        2 1   1 2 
            1 
Explanation
Catch the pattern and print it accordingly.
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int nsp1=n-1,nsp2=-1,nst=1;
    for(int row=1;row<=n;row++) {
        int val;
        if(row<= n/2+1) {
            val=row;
        }
        else {
            val = n-row+1;
        }

        for(int csp=1;csp<=nsp1;csp++) {
            cout << "  ";
        }

        for(int cst=1;cst<=nst;cst++) {
            cout<< val << " ";
            val--;
        }
        for(int csp=1;csp<=nsp2;csp++) {
            cout<< "  ";
        }

        int cst=1;
        val++;
        if(row==1||row==n) {
            cst=2;
        }

        for(;cst<=nst;cst++) {
            cout << val << " ";
            val++;
        }

        if(row<=n/2) {
            nsp1-=2;
            nst++;
            nsp2+=2;
        }
        else {
            nsp1+=2;
            nst--;
            nsp2-=2;
        }
        cout << endl;
    }
    return 0;
}