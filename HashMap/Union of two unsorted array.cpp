#include <iostream>
#include <unordered_set>

using namespace std;

int unionCount(int a[],int b[],int m,int n)
{
    unordered_set<int> h(a,a+n);
    for(int i=0;i<m;i++)
    {
        h.insert(b[i]);
    }
    return h.size();
}

int main()
{
    int a[]={15,20,5,15};
    int b[]={15,15,15,20,10};
    int n=4,m=5;
    cout<<unionCount(a,b,m,n);

    return 0;
}
