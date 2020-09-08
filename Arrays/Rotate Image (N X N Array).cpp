/* Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

Input Format
First line contains a single integer N. Next N lines contain N space separated integers.

Constraints
N < 1000

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 
Explanation
Rotate the array 90 degrees anticlockwise.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i,j ;
  cin>>n;
  int arr[n][n];
  int right = n-1, up = 0 , down = n-1;
  for(i = 0 ; i  < n ; i++)
    for(j = 0 ; j < n ; j ++ )
      cin>>arr[i][j];

for(i = right ; i >= 0 ; i--)
{ 
for(j = up ; j <= down ; j++ )
{
cout<<arr[j][i]<<" ";
}
cout<<endl;
}


      return 0;
}