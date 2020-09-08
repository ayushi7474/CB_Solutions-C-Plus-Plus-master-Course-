/*
Take N (number of rows), print the following pattern (for N = 4).

                       1 
                     2 3 2
                   3 4 5 4 3
                 4 5 6 7 6 5 4
Input Format
Constraints
0 < N < 10

Output Format
Sample Input
4
Sample Output
            1
		2	3	2
	3	4	5	4	3
4	5	6	7	6	5	4
Explanation
Each number is separated from other by a tab.
*/
#include<iostream>
using namespace std;

int main() {

	int n,k,i,j,m,l;
	cin >> n;
	for (i=1;i<=n;i++) {
	    k=1;
		while(k<=n-i) {
			cout  << "   ";
			k++;
			
		}
		k=i;
		m=1;
		for (j=1;j<=2*i-1;j++) {
		    if(k<=2*i-1) {
		        cout << k << "  ";
		        l=k;
			    k++;
		    }
		    else {
		        l--;
		        cout << l << "  ";
		        
		    }
			m++;
		}

		cout << endl;
	}
	return 0;
}