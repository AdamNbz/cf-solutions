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
    vector<pair<int, int>> a(n); for (auto &x: a) cin >> x.first >> x.second;
    int cnt1 = 0, cnt2 = 0;
    for (int i=0; i<n; i++) cnt1 += (a[i].first > a[i].second), cnt2 += (a[i].first < a[i].second);
    cout << (cnt1 > cnt2 ? "Mishka" : cnt1 < cnt2 ? "Chris" : "Friendship is magic!^^");
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}