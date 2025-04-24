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
    int n; ll k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    bool has = 0, ok = 1;
    ll x = 0;
    for (int i=0; i<n; i++)
    {
        if (b[i] != -1) 
        {
            ll tmp = a[i] + b[i];
            if (!has) has = 1, x = tmp;
            else if (x != tmp) 
            {
                ok = 0;
                break;
            }
        }
    }
    if (!ok) 
    {
        cout << 0 << '\n';
        return;
    }

    if (has)
    {
        for (int i=0; i<n; i++)
        {
            if (b[i] == -1) 
            {
                ll tmp = x - a[i];
                if (tmp < 0 || tmp > k) 
                {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? 1:0) << '\n';
    }
    else
    {
        ll l = a[0], r = a[0]+k;
        for (int i=1; i<n; i++) ckmax(l, 1ll*a[i]), ckmin(r, 1ll*a[i]+k);
        cout << (r >= l ? r-l+1 : 0) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}