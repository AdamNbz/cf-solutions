#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

bool prime(int n)
{
    for (int i=2; i*i<=n; i++) if (n%i==0) return 0;
    return n>=2;
}

void skibidi()
{
    int x, k; cin >> x >> k;
    if (x > 1 && k > 1) 
    {
        cout << "NO" << '\n';
        return;
    }

    int ans = x;
    for (int i=1; i<k; i++) ans *= 10 + x;
    cout << (prime(ans) ? "YES" : "NO") << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}