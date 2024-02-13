/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <limits.h>

using namespace std;

int eggDropRes(int e,int f)//recursive solution
{
    if(f==1 || f==0)
        return f;
    if(e==1)
        return f;
    int min=INT_MAX,x,res;
    for(x=1;x<=f;x++)
    {
        res=max(eggDropRes(e-1,x-1),eggDropRes(e,f-x));
        if(res<min)
            min=res;
    }
    return min+1;
}

int eggDropDP(int e,int f)//Dp solution withe time complexity of O(f^2e) and space o(fe)
{
    int dp[f+1][e+1];
    for(int i=1;i<=e;i++)
    {
        dp[1][i]=1;
        dp[0][i]=0;
    }
    for(int j=1;j<=f;j++)
    {
        dp[j][1]=j;
    }
    for(int i=2;i<=f;i++)
    {
        for(int j=2;j<=e;j++)
        {
            dp[i][j]=INT_MAX;
            for(int x=1;x<=i;x++)
            {
                dp[i][j]=min(dp[i][j], 1 + max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }
    return dp[f][e];
}

int main()
{
    int e=3,f=10;
    cout << "Minimum number of trials in worst case with "<< e << " eggs and " << f << " floors using Recursion is "<< eggDropRes(e, f) << endl;
    cout << "Minimum number of trials in worst case with "<< e << " eggs and " << f << " floors using DP is "<< eggDropDP(e, f) << endl;

    return 0;
}