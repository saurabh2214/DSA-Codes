#include <iostream>
#include <unordered_set>

using namespace std;

bool isPair(int arr[],int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
                return true;
        }
    }
    return false;
}

bool isPairhash(int arr[],int n,int sum)
{
    unordered_set<int> h;
    for(int i=0;i<n;i++)
    {
        if(h.find(sum-arr[i])!=h.end())
            return true;
        else
            h.insert(arr[i]);
    }
    return false;
}

int main()
{
    int arr[]={3,2,8,15,-8};
    int n=5;
    int sum=17;
    
    cout<<isPair(arr,n,sum)<<endl;
    cout<<isPairhash(arr,n,sum);
    return 0;
}
