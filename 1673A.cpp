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
    int ans = 0;
    for (auto x: s) ans += (x-'a'+1);
    if (s.size() % 2 == 0)
    {
        cout << "Alice " << ans << '\n';
        return;
    }
    if (s.size() == 1)
    {
        cout << "Bob " << s[0]-'a'+1 << '\n';
        return;
    }

    int ans2 (s[0] <= s[s.size()-1] ? s[0]-'a'+1 : s[s.size()-1]-'a'+1);
    ans -= ans2;
    cout << (ans < ans2 ? "Bob " : ans > ans2 ? "Alice " : "Draw ") << abs(ans-ans2) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}