/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int largest_sum(int arr[],int n)
{
    vector<int> dp(n,0);
    int maxi=INT_MIN;
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(arr[i],arr[i]+dp[i-1]);
        maxi=max(dp[i],maxi);
    }
    return maxi;
}

int main()
{
    int n=5;
    int a[5]={5,4,-1,7,8};
    int ans=largest_sum(a,n);
    cout<<ans<<endl;

    return 0;
}