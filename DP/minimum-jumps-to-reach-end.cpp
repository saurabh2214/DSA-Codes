/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <limits.h>

using namespace std;

int minJumpdp(int arr[],int n)// Dp solution with time complexity of O(n^2) and extra space of O(n)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=INT_MAX;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]+j >=i)
            {
                if(dp[j]!=INT_MAX)
                    dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int minJumprec(int arr[],int n)// Recursion Based Solution 
{
    if(n==1)
        return 0;
    int res=INT_MAX;
    for(int i=0;i<=n-2;i++)
    {
        if(i+arr[i]>=n-1)
        {
            int sub=minJumprec(arr,i+1);
            if(sub!=INT_MAX)
                res=min(res,sub+1);
        }
    }
    return res;
}

int main()
{
    int arr[]={3,4,2,1,2,1};
    int n=6;
    cout<<"Dp based Solution: "<<minJumpdp(arr,n)<<endl;
    cout<<"Recursion based Solution: "<<minJumprec(arr,n)<<endl;

    return 0;
}