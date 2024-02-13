/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <limits.h>

using namespace std;

int sum(int arr[],int b,int e )
{
    int s=0;
    for(int i=b;i<=e;i++)
    {
        s+=arr[i];
    }
    return s;
}

int minPageR(int arr[],int n,int k)//Recursive solution with exponential time complexity
{
    if(k==1)
        return sum(arr,0,n-1);
    if(n==1)
        return arr[0];
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        res=min(res,max(minPageR(arr,i,k-1),sum(arr,i,n-1)));
    }
    return res;
}

int minPageD(int arr[],int n,int k)
{
    int dp[k+1][n+1];
    for(int i=1;i<=n;i++)
        dp[1][i]=sum(arr,0,i-1);
    for(int i=1;i<=k;i++)
        dp[i][1]=arr[0];
    for(int i=2;i<=k;i++)
    {
        for(int j=2;j<=n;j++)
        {
            int res=INT_MAX;
            for(int p=1;p<j;p++)
            {
                res=min(res,max(dp[i-1][p],sum(arr,p,j-1)));
            }
            dp[i][j]=res;
        }
    }
    return dp[k][n];
}

int main()
{
    int arr[]={10,20,30,40};
    int k=2;
    int n=4;
    cout<<"Minimum no of pages using recusive sol is "<<minPageR(arr,n,k)<<endl;
    cout<<"Minimum no of pages using DP sol is "<<minPageD(arr,n,k);

    return 0;
}