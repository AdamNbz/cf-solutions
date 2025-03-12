#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

void skibidi()
{
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    
    vector<int> ans(n, (1<<30)-1);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j) ans[i] &= a[i][j], ans[j] &= a[i][j];
    

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j && (ans[i] | ans[j]) != a[i][j])
            {
                cout << "NO\n";
                return;
            }
    
    cout << "YES\n";
    for (int i=0; i<n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}