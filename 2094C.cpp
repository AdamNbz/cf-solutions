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
    vector<vector<int>> grid(n, vector<int>(n));
    vector<bool> yes((n<<1)+1, 0);
    vector<int> ans;
    for (auto &i: grid) for (auto &j: i) 
    {
        cin >> j;
        if (!yes[j]) 
        {
            yes[j] = 1;
            ans.push_back(j);
        }
    }
    for (int i=1; i<=2*n; i++) 
    {
        if (!yes[i]) 
        {
            cout << i << " ";
            break;
        }
    }
    for (auto x: ans) cout << x << " ";
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}