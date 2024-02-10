#include <iostream>
#include <unordered_set>

using namespace std;

bool is0Subarray(int arr[],int n)//Naive Solution with TC=O(n^2)
{
    for(int i=0;i<n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==0)
                return true;
        }
    }
    return false;
}

bool is0SubarrayHash(int arr[],int n)//Efficent Solution with TC=O(n) 
{
    unordered_set<int> h;
    int pre_sum=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=arr[i];
        if(h.find(pre_sum)!=h.end())
            return true;
        if(pre_sum==0)
            return true;
        h.insert(pre_sum);
    }
    return false;
}

int main()
{
    int arr[]={1,4,13,-3,-10,5};
    int n=6;
    
    if(is0Subarray(arr,n)==true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
        
    if(is0SubarrayHash(arr,n)==true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}