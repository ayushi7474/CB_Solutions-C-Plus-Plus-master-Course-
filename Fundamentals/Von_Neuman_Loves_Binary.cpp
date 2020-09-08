/*
Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.

Input Format
The first line contains N , the number of binary numbers. Next N lines contain N integers each representing binary represenation of number.

Constraints
N<=1000 Digits in binary representation is <=16.

Output Format
N lines,each containing a decimal equivalent of the binary number.

Sample Input
4
101
1111
00110
111111
Sample Output
5
15
6
63
Explanation
For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	  int n, i = 0, ans = 0, rem = 0;
	  cin>>n;
	  while(n != 0)
	  {
		  rem = n % 10;
		  ans = ans + rem * pow(2, i);
		  i++;
		  n = n / 10;
	  }	
	  cout<<ans<<endl;
	}
	return 0;
}