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
    int a[101]; for (int i=0; i<n; i++) cin >> a[i];
    if (a[0] != a[1] && a[0] != a[2])
    {
        cout << 1 << '\n';
        return;
    }
    if (a[n-1] != a[n-2] && a[n-1] != a[n-3])
    {
        cout << n << '\n';
        return;
    }

    for (int i=1; i<n-1; i++) if (a[i] != a[i-1] && a[i] != a[i+1])
    {
        cout << i+1 << '\n';
        return;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}