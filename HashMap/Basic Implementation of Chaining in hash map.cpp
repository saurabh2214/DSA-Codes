#include <bits/stdc++.h>

using namespace std;

struct MyHash
{
    int bucket;
    list<int> *table;
    MyHash(int b)
    {
        bucket=b;
        table=new list<int>[bucket];
    }
    void insert(int key)
    {
        int i=key%bucket;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i=key%bucket;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i=key%bucket;
        for(auto x:table[i])
            if(x==key)
                return true;
        return false;
    }
};

int main()
{
    int n=7;
    MyHash mh(n);
    mh.insert(70);
    mh.insert(71);
    mh.insert(9);
    mh.insert(56);
    mh.insert(72);
    cout << mh.search(9) << endl;
	mh.remove(71);
	cout << mh.search(71);
    

    return 0;
}
