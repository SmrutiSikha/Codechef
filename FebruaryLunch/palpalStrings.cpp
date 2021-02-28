#include "bits/stdc++.h"

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<char,int> mp;
        string s;
        cin>>s;
        for(int i = 0 ; i < s.length() ; i++)
        {
            mp[s[i]]++;
        }
        map<char,int>::iterator it;
        int oddCount = 0;
        int evenCount = 0;
        for(it = mp.begin() ; it != mp.end() ; it++)
        {
            if((*it).second == 1)
            {
                oddCount++;
            }
            else if((*it).second%2 == 0)
            {
                evenCount++;
            } 
        }
        if(oddCount > evenCount)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}