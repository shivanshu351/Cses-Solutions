#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LLONG_MAX >> 1;
class DisjointSet
{
    public:
    vector<int> parent,sizes;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        sizes.resize(n+1,1);

        for(int i=0;i<=n;++i)
        {
            parent[i]=i;
        }
    }
    int uParent(int node)
    {
        if(parent[node]==node)
        {
            return parent[node];
        }
        return parent[node]=uParent(parent[node]);
    }
    void unionS(int u,int v)
    {
        int upar = uParent(u);
        int vpar = uParent(v);

        if(upar==vpar)
        {
            return;
        }
        if(sizes[upar]>sizes[vpar])
        {
            parent[vpar]=upar;
            sizes[vpar]+=sizes[upar];
        }
        else
        {
            parent[upar]=vpar;
            sizes[upar]+=sizes[vpar];
        }
    }
};
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    DisjointSet ds(n);
    vector<int> adj[n+1];
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
    {
        for(auto &vals:adj[i])
        {
            int u = i;
            int v = vals;
            if(ds.uParent(u)!=ds.uParent(v))
            {
                ds.unionS(u,v);
            }
        }
    }
    vector<int> nodes;
    for(int i=1;i<=n;++i)
    {
        if(ds.parent[i]==i)
        {
            nodes.push_back(ds.parent[i]);
        }
    }
    int s = nodes.size();
    cout<<s-1<<endl;
    for(int i=0;i<s-1;++i)
    {
        cout<<nodes[i]<<" "<<nodes[i+1]<<endl;
    }

    return 0;
}