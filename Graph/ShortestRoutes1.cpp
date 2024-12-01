#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n, m;
    cin >> n >> m;
 
 
    vector<long long> dist(n + 1, LLONG_MAX);
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> st;
 
 
    st.push({0, 1});
    dist[1] = 0;
    
    vector<pair<int, long long>> adj[n + 1];
 
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        long long c; 
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    
    while (!st.empty())
    {
        long long wtt = st.top().first; 
        int u = st.top().second; 
        
        st.pop();
        if(wtt>dist[u])
        {
            continue;
        }
        for (const auto &vals : adj[u])
        {
            int v = vals.first;
            long long wt = vals.second;
 
            if (wt + wtt < dist[v])
            {
                dist[v] = wt + wtt;
                st.push({dist[v], v}); 
            }
        }
    }
 
 
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] != LLONG_MAX)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << "INF ";
        }
    }
    cout << endl; 
 
    return 0;
}