#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LLONG_MAX >> 1;

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //unordered_set is not working
    set<int> st;
    int n; cin >> n;
    for(int i=0;i<n;++i)
    {
        int ele;
        cin >> ele;
        st.insert(ele);
    }
    int ans = st.size();
    cout<<ans<<endl;

    return 0;
}