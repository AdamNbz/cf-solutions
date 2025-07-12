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
    vector<int> ones, twos, threes;
    for (int i=1; i<=n; i++)
    {
        int x; cin >> x;
        if (x == 1) ones.push_back(i);
        else if (x == 2) twos.push_back(i);
        else threes.push_back(i);
    }
    if (ones.empty() || twos.empty() || threes.empty())
    {
        cout << "0\n";
        return;
    }

    cout << min({ones.size(), twos.size(), threes.size()}) << '\n';
    for (int i=0; i<min({ones.size(), twos.size(), threes.size()}); i++)
    {
        cout << ones[i] << ' ' << twos[i] << ' ' << threes[i] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}