#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LLONG_MAX >> 1;
int dfs(vector<int> &dp,vector<int> &nums,int target,int MOD)
{
    if(target<0)
    {
        return 0;
    }
    if(target==0)
    {
        return 1;
    }
    if(dp[target]!=-1)
    {
        return dp[target];
    }
    int ways=0;
    for(int i=0;i<nums.size();++i)
    {
        if(target-nums[i]>=0)
        ways=(ways+dfs(dp,nums,target-nums[i],MOD))%MOD;
    }
    return dp[target]=ways;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int  n ,x;
    cin >> n >> x;
    vector<int> dp(x+1,-1);
    vector<int> nums(n,0);
    for(int i=0;i<n;++i)
    {
        cin >> nums[i];
    }
    // cout<<dfs(dp,nums,x,MOD)%MOD<<endl;


    dp[0]=1;
    for(int i=1;i<=x;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(x-nums[j]>=0)
            {
                dp[i]=(dp[i]+dp[i-nums[j]])%MOD;
            }
        }
    }
    return dp[x];
}