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
    string s; cin >> s;
    int cnt = 1, ans = 0;
    for (int i=1; i<s.size(); i++)
    {
        if (s[i] != s[i-1])
        {
            cerr << cnt << '\n';
            ckmax(ans, cnt);
            cnt = 1;
        }
        else cnt++;
    }
    ckmax(ans, cnt);
    cout << (ans >= 7 ? "YES" : "NO");
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}