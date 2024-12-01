#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LLONG_MAX >> 1;


//Memoize the number of ways to visit a particular node
int dfs(vector<int> &dp,vector<int> adj[],int node,int target,int MOD)
{
    if(node == target)
    {
        return 1;
    }
    if(dp[node]!=-1)
    {
        return dp[node];
    }
    int ways=0;
    for(auto &vals:adj[node])
    {
        ways=(ways+dfs(dp,adj,vals,target,MOD))%MOD;
    }
    return dp[node]=ways%MOD;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n , m;
    cin >> n >> m;
    vector<int> dp(n+1,-1);
    vector<int> adj[n+1];
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ways = dfs(dp,adj,1,n,MOD);
    cout<<ways%MOD<<endl;
    return 0;
}