/* We are given a circular array, print the next greater number for every element. 
If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

Input Format
First line contains the length of the array n. Second line contains the n space separated integers.

Constraints
1 <= n <= 10^6
-10^8 <= Ai <= 10^8 , 0<= i< n

Output Format
Print n space separated integers each representing the next greater element.

Sample Input
3
1 2 3
Sample Output
2 3 -1
Explanation
Next greater element for 1 is 2,
for 2 is 3 but not present for 3 therefore -1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,ele, prev;
	cin>>n;
	queue <int> q;
	cin>>ele;
	prev = ele;
	q.push(ele);
	for(i = 1 ; i < n ; i ++)
	{
	  cin>>ele;
	  q.push(ele);
	  if(ele > prev)
	  cout<<ele<<" ";
	else
		cout<<"-1"<<" ";
	  prev = ele;
		}
	if(q.front() > q.back())
		 cout<<ele<<" ";
	else
		cout<<"-1"<<" ";
return 0;
}