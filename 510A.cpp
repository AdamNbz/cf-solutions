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
    int n, m; cin >> n >> m;
    bool flip = 1;
    for (int i=0; i<n; i++)
    {
        if (!(i%2)) for (int j=0; j<m; j++) cout << "#";
        else 
        {
            if (flip) 
            {
                for (int j=0; j<m-1; j++) cout << ".";
                cout << "#";
                flip = 0;
            }
            else
            {
                cout << "#";
                for (int j=0; j<m-1; j++) cout << ".";
                flip = 1;
            }
        }
        cout << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}