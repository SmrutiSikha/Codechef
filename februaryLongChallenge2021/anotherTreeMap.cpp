#include "bits/stdc++.h"

using namespace std;

void query(int v,int w,map<int,list<int> > vec,int& ans)
{
    if(vec.find(v) == vec.end())
    {
        return;
    }
    if(w%vec[v].size() == 0)
    {
         w = w/vec[v].size();
        list<int>::iterator i;
        for (i = vec[v].begin(); i != vec[v].end(); ++i)
        {
            query(*i,w,vec,ans);
        }
    }
    else if(w%vec[v].size() != 0)
    {
       ans += w;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    map<int,list<int> > v;
    for(int i = 2 ; i < n+1 ; i++)
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,w;
        cin>>x>>w;
        int ans =0;
        query(x,w,v,ans);
        cout<<ans<<"\n";
    }
}