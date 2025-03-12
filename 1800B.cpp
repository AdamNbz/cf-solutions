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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    int l[26] = {0}, u[26] = {0};
    for (auto x: s) if (islower(x)) l[x-'a']++; else u[x-'A']++;

    ll ans = 0;
    for (int i=0; i<26; i++)
    {
        if (l[i] == u[i]) ans += l[i];
        else 
        {
            ans += min(l[i], u[i]);
            ans += min(k, (abs(l[i]-u[i]))/2);
            k -= min(k, (abs(l[i]-u[i]))/2);
        }
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