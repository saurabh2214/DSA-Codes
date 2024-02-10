#include <iostream>
#include <unordered_map>

using namespace std;

void printFreq(int arr[],int n)//Naive Solutio with time O(n^2)
{
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
        if(flag==true)
            continue;
        int freq=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
                freq++;
            
        }
        cout<<arr[i]<<" "<<freq<<endl;
    }
}

void printFreqHash(int arr[],int n)//Efficient Solution with time O(n)
{
    unordered_map<int,int> h;
    for(int i=0;i<n;i++)
        h[arr[i]]++;
    for(auto e:h)
        cout<<e.first<<" "<<e.second<<endl;
}

int main()
{
    int arr[]={10,12,10,15,10,20,12,12};
    int n=8;
    printFreq(arr,n);
    cout<<endl;
    printFreqHash(arr,n);

    return 0;
}
