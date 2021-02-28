#include "bits/stdc++.h"

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<int,long long int,greater<int> > mp;
        for(int i = 1 ; i <= 10 ; i++)
        {
            long long int x;
            cin>>x;
            if(x==0)
            {
                continue;
            }
            mp[i] = x;
        }
        long long int k;
        cin>>k;
        map<int,long long int>::iterator itr = mp.begin();
        if(k == 0)
        {
            cout<<(*itr).first<<endl;
        }
        else
        {
            int ans = -1;
            while(k > 0 && mp.size() > 0)
            {
                 if(k > (*itr).second)
                 {
                     k = k - (*itr).second;
                     mp.erase(itr);
                     itr = mp.begin();
                     ans = (*itr).first;
                 }
                 else
                 {
                     int p = k;
                     k =  k - (*itr).second;
                     (*itr).second = (*itr).second - p;
                     if((*itr).second == 0)
                     {
                       mp.erase(itr);
                       itr = mp.begin();
                     }
                     ans = (*itr).first;
                     if(k <= 0)
                     {
                         cout<<ans<<endl;
                         break;
                     }
                 }
            }
        }
    }
}