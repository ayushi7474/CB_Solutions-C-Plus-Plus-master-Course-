/* Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
Explanation
For spiral level anti-clockwise traversal, Go for first column-> last row ->last column-> first row and then do the same traversal for the remaining matrix .
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int m,n,i,j, dir = 1 ;
  cin>>m>>n;
  int arr[m][n];
  int left = 0 , right = n-1 , up = 0, down = m-1;
  for(i = 0 ; i  < m ; i++)
    for(j = 0 ; j < n ; j ++ )
      cin>>arr[i][j];
while(up <= down && left <= right)
{  if(dir == 1 && up <= down && left <= right) //up to down
  {
    for(i = up ; i <= down; i ++)
    cout<<arr[i][left]<<", ";
    left++;
    dir++;
  }
  if(dir == 2 && up <= down && left <= right) //left to right
  {
    for(i = left; i <= right ; i++)
    cout<<arr[down][i]<<", ";
    down--;
    dir++;
  }
  if(dir == 3 && up <= down && left <= right) //down to up
  {
    for(i = down ; i >= up ; i--)
    cout<<arr[i][right]<<", ";
    right--;
    dir++;
  }
  if(dir == 4 && up <= down && left <= right) //right to left
  {
    for(i = right ; i >= left ; i-- )
    cout<<arr[up][i]<<", ";
    up++;
    dir = 1;
  }
  
} 
  cout<<"END";
  return 0;

}