/*Given a list of numbers, stop processing input after the cumulative sum of all the input becomes negative.

Input Format
A list of integers to be processed

Constraints
All numbers input are integers between -1000 and 1000.

Output Format
Print all the numbers before the cumulative sum become negative.

Sample Input
1
2
88
-100
49
Sample Output
1
2
88 */
#include<iostream>
using namespace std;
int main()
{
    int n[100],sum=0;
    int i;
    
    for(i=0;sum>=0;i++) {
        cin >> n[i];
        sum=sum+n[i];
    }
    
    for(int j=0;j<i-1;j++){
        cout << n[j] << endl;
    }
    
    return 0;
}