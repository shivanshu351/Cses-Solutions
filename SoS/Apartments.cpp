#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9+7;
const int INF = LLONG_MAX >> 1;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n , m , k;
    cin >> n >> m >>k;

    vector<int> a(n,0);
    vector<int> b(m,0);
    
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    for(int j=0;j<m;++j)
    {
        cin >> b[j];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0;int j=0;
    int cnt=0;
    while(i<a.size() && j<b.size())
    {   
        if(abs(a[i]-b[j])<=k)
        {
            ++cnt;
            ++i;
            ++j;
        }
        else if(a[i]-b[j]>k)
        {
            ++j;
        }
        else
        {
            ++i;
        }
    }
    cout<<cnt<<endl;
    return 0;
}