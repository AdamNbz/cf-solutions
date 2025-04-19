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
    vector<vector<ll>> h(n, vector<ll>(n));
    vector<ll> a(n), b(n);
    for (auto &i: h) for (auto &x: i) cin >> x;
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    vector<int> c(n-1, 0b111), d(n-1, 0b111);
    bool ok = 0;
    for(int i = 0; i < n-1; i++)
    {
        int &crr = c[i];
        for(int j = 0; j < n; j++)
        {
            ll dif = h[i+1][j] - h[i][j];
            if (-1 <= dif && dif <= 1) crr &= ~(1 << int(dif + 1));
        }
        if (!crr) { ok = 1; break; }
    }

    for(int j = 0; j < n-1; j++){
        int &crr = d[j];
        for(int i = 0; i < n; i++){
            ll dif = h[i][j+1] - h[i][j];
            if (-1 <= dif && dif <= 1){
                crr &= ~(1 << int(dif + 1));
            }
        }
        if (!crr) { ok = 1; break; }
    }

    if (ok)
    {
        cout << -1 << "\n";
        return;
    }

    ll dp0 = 0, dp1 = a[0];
    for(int i = 0; i < n-1; i++)
    {
        ll ndp0 = inf, ndp1 = inf;
        int yes = c[i];
        for (int s = 0; s < 2; s++)
        {
            ll cur = (!s ? dp0 : dp1);
            if (cur >= inf) continue;
            for (int t = 0; t < 2; t++)
            {
                int dif = s - t + 1;
                if (yes & (1<<dif))
                {
                    ll cost = cur + (t ? a[i+1] : 0);
                    if (!t) ndp0 = min(ndp0, cost);
                    else ndp1 = min(ndp1, cost);
                }
            }
        }
        dp0 = ndp0;
        dp1 = ndp1;
    }
    ll best = min(dp0, dp1);

    ll dq0 = 0, dq1 = b[0];
    for(int j = 0; j < n-1; j++)
    {
        ll ndq0 = inf, ndq1 = inf;
        int yes = d[j];
        for(int s = 0; s < 2; s++)
        {
            ll cur = (!s ? dq0 : dq1);
            if (cur >= inf) continue;
            for (int t = 0; t < 2; t++)
            {
                int dif = s - t + 1;
                if (yes & (1<<dif))
                {
                    ll cost = cur + (t ? b[j+1] : 0);
                    if (t==0) ndq0 = min(ndq0, cost);
                    else ndq1 = min(ndq1, cost);
                }
            }
        }
        dq0 = ndq0;
        dq1 = ndq1;
    }
    ll best2 = min(dq0, dq1);

    ll ans = (best < inf && best2 < inf ? best+best2:-1LL);
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}