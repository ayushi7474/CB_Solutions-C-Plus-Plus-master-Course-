/* Take as input a two-d array. Wave print it column-wise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END
*/
#include<iostream>
using namespace std;
int main() {
	int m,n,i,j, dir = 0; //0 -- ud, 1 -- du
    cin>>m>>n;
	int arr[m][n];
	for(i = 0 ; i < m ; i ++)
	for(j = 0 ; j < n ; j++)
	cin>>arr[i][j]; 
	j = 0;
	while(j < n){
  if(dir == 0 && j < n)
	{
		for(i = 0 ; i < m ; i++)
		cout<<arr[i][j]<<", ";
		dir = 1;
		j++;
	}
	if(dir == 1 && j < n)
	{
		for(i = m-1 ; i >= 0 ; i--)
		cout<<arr[i][j]<<", ";
		dir = 0;
		j++;
	}
  }
cout<<"END";
return 0;
}