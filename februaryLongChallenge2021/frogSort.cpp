#include "bits/stdc++.h"

using namespace std;

bool compare(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    return a.first.first < b.first.first;
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int w[n];
        int l[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin>>w[i];
        }
        for(int i = 0 ; i < n ; i++)
        {
            cin>>l[i];
        }
        vector<pair<pair<int,int>,int> > v;
        for(int i = 0 ; i < n ; i++)
        {
            pair<int,int> p(w[i],l[i]);
            pair<pair<int,int>,int> q(p,i);
            v.push_back(q);
        }
        sort(v.begin(),v.end(),compare);
        // for(int i = 0 ; i < n ; i++)
        // {
        //     cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
        // }
        int ans = 0;
        for(int i = 1 ; i < n ; i++)
        {
            while(v[i].second <= v[i-1].second)
            {
                ans++;
                v[i].second = v[i].second + v[i].first.second;
            }
        }
        cout<<ans<<endl;
    }
}