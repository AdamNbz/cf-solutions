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
    vector<int> ans;
    int cnt=0;
    while (n)
    {
        if (n%10) ans.push_back((n%10)*pow(10, cnt));
        n /= 10;
        cnt++;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x: ans) if (x) cout << x << " ";
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}