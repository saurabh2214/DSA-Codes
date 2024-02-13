/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int maxSumR(int arr[],int n)//Recursive Solution with time complexity of O(2^n)
{
    if(n==1)
        return arr[0];
    else if( n==2)
        return max(arr[0],arr[1]);
    else
        return max(maxSumR(arr,n-1),maxSumR(arr,n-2)+arr[n-1]);
}

int maxSumD(int arr[],int n)//DP Solution with time complexity of O(n) and auxilary Space of O(n)
{
    if(n==1)
        return arr[0];
    int dp[n+1];
    dp[1]=arr[0];
    dp[2]=max(arr[0],arr[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i-1]);
    }
    return dp[n];
}

int maxSumS(int arr[],int n)//It is a Space optmized Solution of MaxSum
{
    if(n==1)
        return arr[0];
    int prev_prev=arr[0];
    int prev=max(arr[0],arr[1]);
    int res=prev;
    for(int i=3;i<=n;i++)
    {
        res=max(prev,prev_prev+arr[i-1]);
        prev_prev=prev;
        prev=res;
    }
    return res;
}

int main()
{
    int arr[]={8,7,6,10};
    int n=4;
    cout<<"Maximim Sum from array using recursion is "<<maxSumR(arr,n)<<endl;
    cout<<"Maximim Sum from array using dp is "<<maxSumD(arr,n)<<endl;
    cout<<"Maximim Sum from array using space optimized is "<<maxSumS(arr,n)<<endl;

    return 0;
}