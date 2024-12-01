#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = 1e9;

int32_t main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    // Reading edges and negating weights to find maximum path
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_tuple(a, b, -c));
    }

    vector<int> dist(n+1, INF);
    dist[1] = 0;  // Start from node 1

    // Bellman-Ford Algorithm
    for (int i = 0; i < n-1; ++i) {
        for (auto &vals : edges) {   
            int u = get<0>(vals);
            int v = get<1>(vals);
            int wt = get<2>(vals);

            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    bool impos = false;
    for (auto &vals : edges) {
        int u = get<0>(vals);
        int v = get<1>(vals);
        int wt = get<2>(vals);

        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            impos = true;
            break;
        }
    }

    if (impos) {
        cout << "IMPOSSIBLE" << endl;  // Negative cycle detected
    } else {
        if (dist[n] == INF) {
            cout << "IMPOSSIBLE" << endl;  // No path to node n
        } else {
            cout << -dist[n] << endl;  // Output the maximum distance to node n
        }
    }

    return 0;
}
