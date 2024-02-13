/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <limits.h>

using namespace std;

int mChainR(int arr[],int i,int j) //Recurion Solution 
{
    if(i+1==j)
        return 0;
    int res=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        res=min(res,(mChainR(arr,i,k)+ mChainR(arr,k,j)+arr[i]*arr[k]*arr[j]));
    }
    return res;
}

int mChainD(int arr[],int n) //DP solution 
{
    int dp[n][n];
    for(int i=0;i<n-1;i++)
        dp[i][i+1]=0;
    for(int gap=2;gap<n;gap++)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j=i+gap;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                dp[i][j]=min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    int arr[]={2,1,3,4};
    int i=0,j=3;
    cout<<"The Maximum chain multiplcation using Recursion is "<<mChainR(arr,i,j)<<endl;
    cout<<"The Maximum chain multiplcation using DP is "<<mChainD(arr,j+1);

    return 0;
}