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
    if (n < 4) 
    {
        cout << "NO\n";
        return;
    }

    vector<int> ans;
    for (int i=2; i<=n; i+=2) ans.push_back(i);
    for (int i=1; i<=n; i+=2) ans.push_back(i);
    ans[ans.size()-1] += n/2;
    if (ans[ans.size()-1] % 2 == 0)
    {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    for (auto x: ans) cout << x << " ";
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}