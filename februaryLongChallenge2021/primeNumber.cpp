#include "bits/stdc++.h"

using namespace std;

bool dp[1000001];
long long numberPrime[1000001];

void calculatePrime()
{
    for(int i = 0 ; i < 1000001 ; i++)
    {
        dp[i] = true;
        numberPrime[i] = 0;
    }
    for(int i = 2 ; i*i < 1000001 ; i++)
    {
        if(dp[i])
        {
            for(int j = i*i ; j < 1000001 ; j+=i)
            {
                dp[j] = false;
            }
        }
    }
    numberPrime[2] = 1;
    for(int i = 3 ; i < 1000001 ; i++)
    {
        if(dp[i])
        {
            numberPrime[i] = numberPrime[i-1] + 1;
        }
        else
        {
            numberPrime[i] = numberPrime[i-1];
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    calculatePrime();
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x == 1)
        {
            cout<<"Chef"<<"\n";
        }
        else
        {
            long long int count = numberPrime[x];
            if(count > y)
            {
                cout<<"Divyam"<<"\n";
            }
            else
            {
                cout<<"Chef"<<"\n";
            }
        }
    }
}