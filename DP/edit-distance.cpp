/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int edrec(string s1,string s2,int m,int n)//Recursive Solution
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(s1[m-1]==s2[n-1])
        return edrec(s1,s2,m-1,n-1);
    else
        return 1+min(edrec(s1,s2,m,n-1),min(edrec(s1,s2,m-1,n),edrec(s1,s2,m-1,n-1)));
    
}

int eddp(string s1,string s2,int m,int n)//DP solution with time Complexity of theta(m*n) 
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int j=0;j<=n;j++)
        dp[0][j]=j;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}

int main()
{
    string s1="SUNDAY";
    string s2="SATURDAY";
    int m=6;
    int n=8;
    cout<<edrec(s1,s2,m,n)<<endl;
    cout<<eddp(s1,s2,m,n);

    return 0;
}