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

    int n, x;
    cin >> n >> x;
    
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> dp(x + 1, 0); // dp[i] stores the number of ways to make sum 'i'
    dp[0] = 1; // Base case: 1 way to make sum 0 (using no elements)

    // Tabulation process
    for (int target = 1; target <= x; ++target) {
        for (int i = 0; i < n; ++i) {
            if (target - nums[i] >= 0) {
                dp[target] = (dp[target] + dp[target - nums[i]]) % MOD;
            }
        }
    }

    // Output the result
    cout << dp[x] << endl;
    
    return 0;
}