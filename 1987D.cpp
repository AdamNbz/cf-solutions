#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000
#define el '\n'

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const ll mod = (ll)(1e9+7);

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}


void sol()
{
    vi a;
    {
        int n; cin >> n;

        map<int, int> c;
        for (int i=0; i<n; i++) 
        {
            int x; cin >> x;
            c[x]++;
        }
        for (auto &[k, v]: c) a.push_back(v);
    }

    int m = a.size();
    vi dp(m+1, inf);
    dp[0] = 0;
    for (int i=1; i<=m; i++)
    {
        vi ndp = dp;
        for (int k=1; k<=m; k++)
        {
            int nv = dp[k-1] + a[i-1];
            if (nv <= i-k) ndp[k] = min(ndp[k], nv);
        }
        dp = ndp;
    }
    int ans = m;
    while (dp[ans] >= inf) ans--;
    cout << m - ans << el;
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}




