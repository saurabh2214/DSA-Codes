/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int solrec(int arr[] , int i , int j , int sum)//1st recursive solution
{
    if(j==i+1)
        return max(arr[i],arr[j]);
    return max(sum-solrec(arr,i+1,j,sum-arr[i]),
               sum-solrec(arr,i,j-1,sum-arr[j]));
}

int mainSol(int arr[],int n)1st recuris//1st recursive solution
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return solrec(arr,0,n-1,sum);
}

int solrec1(int arr[] , int i , int j)//2nd recursive solution  
{
    if(i+1==j)
        return max(arr[i],arr[j]);
    return max(arr[i]+min(solrec1(arr,i+2,j),
                          solrec1(arr,i+1,j-1)),
               arr[j]+min(solrec1(arr,i+1,j-1),
                          solrec1(arr,i,j-2)));
}

int soldp(int arr[],int n)//dp solution with time complexity and space complexity Theta(n^2)
{
    int dp[n][n];
    for(int i=0;i<n-1;i++)
        dp[i][i+1]=max(arr[i],arr[i+1]);
    for(int gap=3;gap<n;gap=gap+2)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j=i+gap;
            dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),
                         arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
        
    }
    return dp[0][n-1];
}

int main()
{
    int arr[]={20,5,4,6,8,3};
    int n=6;
    cout<<"This is solution using Recursion 1 : "<<mainSol(arr,n) <<endl;
    cout<<"This is solution using Recursion 2 : "<<solrec1(arr,0,n-1)<<endl;
    cout<<"This is solution using dp solution : "<<soldp(arr,n)<<endl;

    return 0;
}