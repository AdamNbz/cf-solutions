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
    vector<int> a(n); for (auto &x: a) cin >> x;

    if (n == 2) 
    {
        cout << min(a[0], a[1]) << '\n';
        return;
    }

    int ans = 0;
    for (int i=0; i<n-2; i++)
    {
        vector<int> crr;
        for (int j=0; j<3; j++) crr.push_back(a[i+j]);
        sort(crr.begin(), crr.end());
        ckmax(ans, crr[1]);
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}