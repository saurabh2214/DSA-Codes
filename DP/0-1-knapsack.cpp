/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int knapsackrec(int w,int wt[],int val[],int n)//recusive solution with time complexoty of O(2^n)
{
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]>w)
        return knapsackrec(w,wt,val,n-1);
    else
        return max(val[n-1]+knapsackrec(w-wt[n-1],wt,val,n-1),knapsackrec(w,wt,val,n-1));
}

int knapsackdp(int w,int wt[],int val[],int n)
{
    int dp[n+1][w+1];
    for(int i=0;i<=w;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][w];
}

int main()
{
    int val[]={10,5,15,7,6};
    int w[]={2,3,5,4,2};
    int n=5;
    int wt=10;
    
    cout<<"The largest val you can get using recursion is: "<<knapsackrec(wt,w,val,n)<<endl;
    cout<<"The largest val you can get using dp is: "<<knapsackdp(wt,w,val,n)<<endl;

    return 0;
}
