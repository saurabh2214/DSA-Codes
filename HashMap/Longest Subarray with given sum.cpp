#include <iostream>
#include <unordered_map>

using namespace std;

int maxlen(int arr[],int n,int sum)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==sum)
                res=max(res,j-i+1);
        }
    }
    return res;
}

int maxlenHash(int arr[],int n,int sum)
{
    unordered_map<int,int> m;
    int pre_sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=arr[i];
        if(pre_sum==sum)
            res=i+1;
        if(m.find(pre_sum)==m.end())
            m.insert({pre_sum,i});
        if(m.find(pre_sum)!=m.end())
            res=max(res,i-m[pre_sum-sum]);
    }
    return res;
}

int main()
{
    int arr[]={5,8,-4,-4,9,-2,2};
    int n=7;
    int sum=0;
    cout<<"Maximum Length is "<<maxlen(arr,n,sum)<<endl;
    cout<<"Maximum Length is using hash "<<maxlenHash(arr,n,sum);
    return 0;
}
