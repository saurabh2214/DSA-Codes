/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int maxcutrec(int n,int a,int b,int c)//Recursive solution but it has time complexity of O(3^n)
{
    if(n<0)
        return -1;
    if(n==0)
        return 0;
    int res=max(maxcutrec(n-a,a,b,c),max(maxcutrec(n-b,a,b,c),maxcutrec(n-c,a,b,c)));
    if(res==-1)
        return res;
    else
        return res+1;
}


int maxcutdp(int n,int a,int b,int c)//dp solution with time complexity and space complexity of Theta(n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        if(i-a>=0)
            dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0)
            dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0)
            dp[i]=max(dp[i],dp[i-c]);
        if(dp[i]!=-1)
            dp[i]++;
    }
    return dp[n];
}

int main()
{
    int n=5;//length
    int a=1;//length that can be cut at once
    int b=2;//length that can be cut at once
    int c=3;//length that can be cut at once
    cout<<maxcutrec(n,a,b,c)<<endl;
    cout<<maxcutdp(n,a,b,c);

    return 0;
}