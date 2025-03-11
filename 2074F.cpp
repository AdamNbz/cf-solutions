#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

void decom(ll l, ll r, vector<ll> &a)
{
    while (l < r)
    {
        ll len = r-l, sz = 1ll << (63-__builtin_clzll(len));
        while ((l & (sz-1))) sz >>= 1;
        a[__builtin_ctzll(sz)]++;
        l += sz;
    }
}

ll invmod[40];

void skibidi()
{
    ll l[2], r[2]; cin >> l[0] >> r[0] >> l[1] >> r[1];
    vector<ll> cntx(25, 0), cnty(25, 0);

    decom(l[0], r[0], cntx);
    decom(l[1], r[1], cnty);

    ll ans = 0;
    for (int i=0; i<cntx.size(); i++)
    {
        if (!cntx[i]) continue;
        for (int j=0; j<cnty.size(); j++)
        {
            if (!cnty[j]) continue;
            ans += cntx[i]*cnty[j]*invmod[abs(i-j)];
        }
    }

    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    invmod[0] = 1;
    for (int i=1; i<40; i++) invmod[i] = invmod[i-1]*2ll;
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}