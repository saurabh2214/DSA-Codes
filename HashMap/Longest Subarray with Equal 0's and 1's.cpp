#include <iostream>
#include <unordered_map>

using namespace std;

int longestSub(int arr[],int n)//Naive Solution with Time Complexity O(n^2)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int c0=0,c1=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==0)
                c0++;
            else
                c1++;
            if(c0==c1)
                res=max(res,c0+c1);
        }
    }
    return res;
}

int longestSubHash(int arr[],int n)//Efficient Solution with Time Complexity O(n)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=(arr[i]==0)?-1:1;
    }
    unordered_map<int,int> ump;
    int sum=0,maxLen=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            maxLen=i+1;
        if(ump.find(sum+n)!=ump.end())
        {
            if(maxLen<i-ump[sum+n])
                maxLen=i-ump[sum+n];
        }
        else
            ump[sum+n]=i;
    }
    return maxLen;
}

int main()
{
    int arr[]={1,0,1,1,1,0,0};
    int n=7;

    cout<<"Equal no of 0 & 1 "<<longestSub(arr,n)<<endl;
    cout<<"Equal no of 0 & 1 using hashmap "<<longestSubHash(arr,n);
    
    return 0;
}
