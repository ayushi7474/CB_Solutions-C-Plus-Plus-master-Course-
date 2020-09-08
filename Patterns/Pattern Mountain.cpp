/* Take N (number of rows), print the following pattern (for N = 4).

                       1           1
                       1 2       2 1  
                       1 2 3   3 2 1
                       1 2 3 4 3 2 1   
Input Format
Constraints
0 < N < 10

Output Format
Sample Input
4
Sample Output
1						1
1	2				2	1
1	2	3		3	2	1
1	2	3	4	3	2	1
Explanation
Each number is separated from other by a tab.
*/
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k;

	for(int i=1;i<=n;i++) {
		k=1;
		for(int j=1;j<=2*n-1;j++) {
			if(j<=i ) {
				
				cout << k << "\t";
				k++;
				
			}
			else if (j>=2*n-i){
				if(k==n+1 && i==n)
				k--;
				k--;
				cout << k << "\t";
			}
			else {
				cout << " \t";
			}
		}
		cout << endl;
	}
	return 0;
}