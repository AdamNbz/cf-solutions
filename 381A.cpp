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

    bool turn = 0;
    int l = 0, r = n-1, s1 = 0, s2 = 0;
    while (l <= r)
    {
        if (turn & 1) s1 += (a[l] > a[r]) ? a[l++] : a[r--];
        else s2 += (a[l] >= a[r]) ? a[l++] : a[r--];
        turn ^= 1;
    }
    cout << s2 << ' ' << s1;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}