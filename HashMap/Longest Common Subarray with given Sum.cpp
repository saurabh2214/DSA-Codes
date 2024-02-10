#include <iostream>
#include <unordered_map>

using namespace std;

int maxCommon(int arr1[],int arr2[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int sum1=0,sum2=0;
        for(int j=i;j<n;j++)
        {
            sum1+=arr1[j];
            sum2+=arr2[j];
            if(sum1==sum2)
                res=max(res,j-i+1);
        }
    }
    return res;
}

int maxCommonHash(int arr1[],int arr2[],int n)
{
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=arr1[i]-arr2[i];
    unordered_map<int,int> hM;
    int sum=0;
    int max_len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            max_len=i+1;
        if(hM.find(sum)!=hM.end())
            max_len=max(max_len,i-hM[sum]);
        else
            hM[sum]=i;
    }
    return max_len;
}

int main()
{
    int arr1[]={0,1,0,1,1,1,1};
    int arr2[]={1,1,1,1,1,0,1};
    int n=7;
    
    cout<<"Maximum Common is "<<maxCommon(arr1,arr2,n)<<endl;
    cout<<"Maximum Common using hash is  "<<maxCommonHash(arr1,arr2,n);

    return 0;
}
