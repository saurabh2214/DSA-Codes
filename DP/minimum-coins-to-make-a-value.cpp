/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>


using namespace std;

int getMin(int coins[],int n,int val)//recursive solution 
{
    if(val==0)
        return val;
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=val)
        {
            int sub=getMin(coins,n,val-coins[i]);
            if(sub!=INT_MAX)
                res=min(res,sub+1);
        }
    }
    return res;
}

int getMindp(int coins[],int n,int val)//dp solution with time complexity of theta(n*val) and space copmlexity of theta(val);
{
    int dp[val+1];
    dp[0]=0;
    for(int i=1;i<=val;i++)
        dp[i]=INT_MAX;
    for(int i=1;i<=val;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i)
            {
                int sub=dp[i-coins[j]];
                if(sub!=INT_MAX)
                    dp[i]=min(dp[i],sub+1);
            }
        }
    }
    return dp[val];
}

int main()
{
    int coins[]={25,10,5};
    int n=3;
    int val=30;
    cout<<"Recursive Solution : "<<getMin(coins,n,val)<<endl;
    cout<<"DP Solution : "<<getMindp(coins,n,val)<<endl;

    return 0;
}

