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
        long long int a[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i];
        }
        if(n == 3)
        {
            long long ans = abs(a[0]-a[1])+abs(a[0]-a[2])+abs(a[2]-a[1]);
            cout<<ans<<endl;
        }
        else
        {
            sort(a,a+n);
            long long ans = 2*abs(a[n-1]-a[0]);
            cout<<ans<<endl;
        }
    }
}