#include "bits/stdc++.h"

using namespace std;

int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
       int n;
       cin>>n;
       map<string,map<char,int> > m;
       for(int i = 0 ; i < n ; i++)
       {
           string s;
           cin>>s;
           string sub = s.substr(1,s.length()-1);
           m[sub].insert(make_pair(s[0],1)); 
       }
       map<string, map<char, int> >::iterator itr; 
       map<string, map<char, int> >::iterator itr1; 
       map<string, map<char, int> >::iterator it;
        map<char, int>::iterator ptr;
        map<char, int>::iterator ptr1;
    int ans = 0;
    for (itr = m.begin(); itr != m.end(); itr++) { 
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) { 
             char c = ptr->first;
             itr1 = itr;
             advance(itr1,1);
             for(it = itr1; it!=m.end(); it++)
             {
                if(it->second.find(c) == it->second.end())
                {
                    for (ptr1 = it->second.begin(); ptr1 != it->second.end(); ptr1++) 
                    {
                        if(itr->second.find(ptr1->first) == itr->second.end())
                        {
                            ans+=2;
                        }
                    }
                }
             }
            
        } 
    } 
    cout<<ans<<endl;
   }
}