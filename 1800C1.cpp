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
    queue<ll> q;
    for (int i=0; i<n; i++) {ll x; cin >> x; q.push(x);}
    ll ans = 0;
    vector<ll> mx;
    while (!q.empty())
    {
        ll x = q.front(); q.pop();
        if (!x)
        {
            if (!mx.size()) continue;
            ans += (*max_element(mx.begin(), mx.end()));
            mx.erase(max_element(mx.begin(), mx.end()));
        }
        else mx.push_back(x);
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