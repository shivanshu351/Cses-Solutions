#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;

int dfs(vector<int> &dp, int target) 
{
    // Base cases
    if (target < 0) {
        return 0;
    }
    if (target == 0) {
        return 1;
    }
    if (dp[target] != -1) {
        return dp[target];
    }

    int ways = 0;
    for (int i = 1; i <= 6; ++i) {
        if (target >= i) {
            ways = (ways + dfs(dp, target - i)) % MOD;
        }
    }

    return dp[target] = ways;
}

int32_t main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;
    
    // Memoization array initialized to -1
    vector<int> dp(n + 1, -1);

    // Compute the result
    int ans = dfs(dp, n);
    
    cout << ans << endl;
    
    return 0;
}
