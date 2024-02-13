/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int countWaysRec(int coins[],int n,int s)//Recursive solution(Naive solution of time complexity of exponential)
{
    if(s==0)
        return 1;
    if(s<0)
        return 0;
    if(n==0)
        return 0;
    return countWaysRec(coins,n,s-coins[n-1])+ countWaysRec(coins,n-1,s);
}

int countWaysdp(int coins[],int n,int s)//DP solution(Navie Solution of time complexity of exponential)
{
    int dp[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int j=1;j<=s;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(coins[i-1]<=j)
                dp[i][j]+=dp[i][j-coins[i-1]];
        }
    }
    return dp[n][s];
}
int main()
{
    int coins[3]={1,2,3};
    int n=3;
    int s=4;
    cout<<countWaysRec(coins,n,s)<<endl;
    cout<<countWaysdp(coins,n,s);

    return 0;
}
