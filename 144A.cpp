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
    int idx1 = 0, idx2 = 0, mx = *max_element(a.begin(), a.end()), mn = *min_element(a.begin(), a.end());
    for (int i=n-1; i>=0; i--) if (a[i] == mx) idx1 = i;
    for (int i=0; i<n; i++) if (a[i] == mn) idx2 = i;
    cout << idx1-1+n-idx2-(idx1 > idx2 ? 1 : 0);
}

signed main()
{   
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}