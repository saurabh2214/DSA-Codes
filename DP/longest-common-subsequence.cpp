/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;


int lcstab(string s1,string s2) //LCS problem solution using tabulation method(time complexity O(m*n))
{
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int lcsmemo(string s1,string s2,int m,int n,vector<vector<int>>& memo)//LCS problem solution using memorization method(time complexity O(m*n))
{
    if(memo[m][n]!=-1)
        return memo[m][n];
    if(m==0 || n==0)
    {
        memo[m][n]=0;
    }
    else
    {
        if(s1[m-1]==s2[n-1])
            memo[m][n]=1+lcsmemo(s1,s2,m-1,n-1,memo);
        else
            memo[m][n]=max(lcsmemo(s1,s2,m-1,n,memo),lcsmemo(s1,s2,m,n-1,memo));
    }
    return memo[m][n];
}


int main()
{
    int m=4;
    int n=3;
    vector<vector<int>> memo(m+1,vector<int> (n+1,-1));
    cout<<lcsmemo("AXYZ","BAZ",m,n,memo)<<endl;
    
    cout<<lcstab("AXYZ","BAZ")<<endl;

    return 0;
}