/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>

using namespace std;

int fib(int n,vector<int>& memo)
{
    if(memo[n]==-1)
    {
        int res;
        if(n==0 || n==1)
            res=n;
        else
            res=fib(n-1, memo)+fib(n-2,memo);
        memo[n]=res;
    }
    return memo[n];
}

int main()
{
    int n;
    cout<<"Enter a Number: ";
    cin>>n;
    vector<int> memo(n+1,-1);
    cout<<"Fibonaci solution for "<<n<<" is " <<fib(n,memo);
}