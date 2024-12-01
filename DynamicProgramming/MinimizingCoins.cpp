#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = 1e9;

int dfs(vector<int> &dp, vector<int> &nums, int target, int index) {
    if (target == 0) {
        return 0; // No coins needed to make sum 0
    }
    if (index == 0) {
        if (target % nums[0] == 0) {
            return target / nums[0]; // Can only use nums[0]
        }
        return INF;
    }
    if (dp[target] != INF) { // Memoized result
        return dp[target];
    }
    int notTake = dfs(dp, nums, target, index - 1); 
    int take = INF;
    if (nums[index] <= target) {
        take = 1 + dfs(dp, nums, target - nums[index], index);
    }
    return dp[target] = min(notTake, take); 
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> dp(x + 1, INF); // Initialize with large values
    dp[0]=0;

    for(int i=1;i<=x;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i-nums[j]>=0)
            {
                dp[i]=min(dp[i],dp[i-nums[j]]+1);
            }
        }
    }

    if(dp[x]!=INF)
    {
        cout<<dp[x]<<endl;
    }
    else
    {
        cout<<-1;
    }

    return 0;
}
