#include <iostream>
#include <unordered_set>

using namespace std;

void intersection(int a[],int m,int b[],int n)
{
    for(int i=0;i<m;i++)
    {
        bool flag=false;
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
            cout<<a[i]<<" ";
    }
}

void intersectionhash(int a[],int b[],int m, int n)
{
    unordered_set<int> s(b,b+n);
    for(int i=0;i<m;i++)
    {
        if(s.find(a[i])!=s.end())
            cout<<a[i]<<" ";
    }
}

int main()
{
    int a[]={10,15,20,25,30,35};
    int b[]={30,5,15,80};
    int m=6;
    int n=4;
    
    intersection(a,m,b,n);
    cout<<endl;
    intersectionhash(a,b,m,n);

    return 0;
}
