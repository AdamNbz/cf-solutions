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
    string s; cin >> s;
    vector<int> ans(n);
    int mex = 0;
    for (auto x: s) mex += (x == '<');
    ans[0] = mex+1;
    int mx = ans[0], mn = ans[0];
    for (int i=0; i<n-1; i++) ans[i+1] = (s[i] == '<' ? --mn : ++mx);
    for (auto x: ans) cout << x << " ";
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}