/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int LISdp(int arr[],int n )//DP Solution with Time Complexity of Theta(n^2) and Auxilary Space of theta(n)
{
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
                lis[i]=max(lis[i],lis[j]+1);
        }
    }
    int res=lis[0];
    for(int i=0;i<n;i++)
    {
        res=max(res,lis[i]);
    }
    return res;
}

int ceildx(int tail[],int l,int r,int x)
{
    while(r>l)
    {
        int m=l+(r-l)/2;
        if(tail[m]>=x)
            r=m;
        else
            l=m+1;
    }
    return r;
}

int LISbs(int arr[],int n)//Binary Search With time complexity of Theta(nlogn) and Auzilary Space of O(n)
{
    int tail[n];
    int len=1;
    tail[0]=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>tail[len-1])
        {
            tail[len]=arr[i];
            len++;
        }
        else
        {
            int c=ceildx(tail,0,len-1,arr[i]);
            tail[c]=arr[i];
        }
    }
    return len;
}

int main()
{
    int a[5]={8,2,3,1,4};
    int n=5;
    cout<<LISbs(a,n)<<endl;
    cout<<LISdp(a,n);
    return 0;
}