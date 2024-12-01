#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LLONG_MAX >> 1;

int32_t main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<int> arr = {1, 2, 3, 4,5};  
    unordered_set<int> st;  
    unordered_map<int, int> mp;  
    
    int i = 0;
    for (auto &vals : arr) {
        mp[vals] = i++; 
    }
    
    int next_index = 0;  
    int n = arr.size();
    vector<int> ans;  

    while (st.size() < n) { 
        next_index = (arr[next_index] + mp[arr[next_index]]) % n; 
        if (st.find(next_index) == st.end())
        {
            ans.push_back(arr[next_index]);  
            st.insert(next_index); 
        }  
        else
        {
            break;
        } 
    }
    for (auto &vals : ans) {
        cout << vals << " "; 
    }
    cout << endl;
    return 0;
}
