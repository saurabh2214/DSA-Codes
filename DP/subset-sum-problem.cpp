/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <limits.h>
#include <cstring>

using namespace std;

int CountSubsetR(int arr[],int n,int sum) //This is Recursive Solution of Time Complexity theta(2^n)
{
    if(n==0)
        return (sum==0)?1:0;
    return CountSubsetR(arr,n-1,sum)+CountSubsetR(arr,n-1,sum-arr[n-1]);
}

int CountSubsetD(int arr[],int n,int sum) //This is DP Solution of Time Complexity theta(n*sum)
{
    int dp[n+1][sum+1];
    
    memset(dp, 0, sizeof(dp));
    
    for(int i=0;i<=n;i++)   dp[i][0]=1;
    for(int j=1;j<=sum;j++)     dp[0][j]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
        }
    }
    return dp[n][sum];
    
}

int main()
{
    int arr[]={10,5,2,3,6};
    int n=5;
    int sum=8;
    cout<<"The subset sum throught recursion is "<<CountSubsetR(arr,n,sum)<<endl;
    cout<<"The subset sum throught DP is "<<CountSubsetD(arr,n,sum);

    return 0;
}