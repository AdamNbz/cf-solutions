#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

vector<pair<char, int>> cmp(string x)
{
    vector<pair<char, int>> ret;
    if (!x.size()) return ret;

    char crr = x[0];
    int cnt = 1;
    for (int i=1; i<x.size(); i++)
        if (x[i] == crr) cnt++;
        else
        {
            ret.push_back({crr, cnt});
            crr = x[i];
            cnt=1;
        }
    ret.push_back({crr, cnt});
    return ret;
}

void skibidi()
{
    string p, s; cin >> p >> s;

    int n = p.size(), m = s.size();
    if (m<n || m > (n<<1)) 
    {
        cout << "NO\n";
        return;
    }

    vector<pair<char, int>> grP = cmp(p), grS = cmp(s);
    if (grP.size() != grS.size()) 
    {
        cout << "NO\n";
        return;
    }

    for (int i=0; i<grP.size(); i++) 
    {
        if (grP[i].first != grS[i].first)
        {
            cout << "NO\n";
            return;
        }

        if (grS[i].second < grP[i].second || grS[i].second > (grP[i].second<<1))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}