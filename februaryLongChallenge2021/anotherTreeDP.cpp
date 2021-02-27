#include "bits/stdc++.h"

using namespace std;

list<int> levelOrder(list<int> tree[])
{
    list<int> level;
    queue<int> q;
    q.push(1);
    list<int>::iterator i;
    while(!q.empty())
    {
        int temp = q.front();
        level.push_back(temp);
        q.pop();
        for (i = tree[temp].begin(); i != tree[temp].end(); ++i)
        {
            q.push(*i);
        }
    }
    return level;
}

void precomputation(list<int> tree[],int** dp)
{
    list<int> level = levelOrder(tree);
    list<int>::iterator it;
    while(!level.empty())
    {
        int k = level.back();
        level.pop_back();
        for(int i = 0 ; i < 1000001 ; i++)
        {
            if(tree[k].size() == 0)
            {
                dp[k][i] = 0;
            }
            else
            {
                int child = tree[k].size();
                if(i%child == 0)
                {
                    dp[k][i] = 0;
                   for (it = tree[k].begin(); it != tree[k].end(); ++it)
                    {
                        dp[k][i] += dp[*it][i/child];
                    }
                }
                else
                {
                   dp[k][i] = i;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    list<int> v[n+1];
    int **dp = new int *[n+1]; // adjacency matrix
    for (int i = 0; i < n+1; i++) {
        dp[i] = new int[1000001];
        for (int j = 0; j < 1000001; j++) {
        dp[i][j] = 0;
        }
    }
    for(int i = 2 ; i < n+1 ; i++)
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    precomputation(v,dp);
    int q;
    cin>>q;
    while(q--)
    {
        int x,w;
        cin>>x>>w;
        cout<<dp[x][w]<<"\n";
    }
}