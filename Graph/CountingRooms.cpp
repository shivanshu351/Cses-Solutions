#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LLONG_MAX >> 1;

void dfs(vector<vector<int>> &visited,vector<vector<char>> &grid,vector<int> &rv,vector<int> &cv,int i,int j)
{   
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
    {
        return;
    }
    visited[i][j]=1;
    for(int k=0;k<4;++k)
    {
        int nr = i+rv[k];
        int nc = j + cv[k];
        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && visited[nr][nc]==0 && grid[nr][nc]=='.')
        {
            dfs(visited,grid,rv,cv,nr,nc);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    vector<vector<int>> visited(n,vector<int>(m,0));

    vector<vector<char>> grid(n,vector<char>(m,' '));

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>grid[i][j];
        }
    }

    int cnt=0;
    vector<int> rv={1,0,-1,0};
    vector<int> cv={0,1,0,-1};

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(!visited[i][j] && grid[i][j]=='.')
            {
                ++cnt;
                dfs(visited,grid,rv,cv,i,j);
            }
        }
    }
    cout<<cnt<<endl;
    

    return 0;
}