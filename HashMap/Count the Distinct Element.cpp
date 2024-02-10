#include <iostream>
#include <unordered_set>

using namespace std;

int CountDistNaive(int arr[],int n)//Naive Solution with time O(n^2) and Space O(1)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
            res++;
    }
    return res;
}

int CountDistHash(int arr[],int n)//Efficient Solution with time O(n) and Space O(n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}

int main()
{
    int arr[]={15,12,13,12,13,13,18};
    int n=7;
    
    cout<<CountDistNaive(arr,n)<<endl;
    cout<<CountDistHash(arr,n)<<endl;

    return 0;
}
