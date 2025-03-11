#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();
const int mxQ = 75;

int qcnt = 0;

int q(int i, int j, int k)
{
    if (qcnt >= mxQ) exit(0);
    cout << "? " << i << ' ' << j << ' ' << k << endl;

    int in; cin >> in;
    if (in == -1) exit(0);
    return in;
}

void ans(int i, int j, int k)
{
    cout << "! " << i << ' ' << j << ' ' << k << endl;
}

void skibidi()
{
    int n; cin >> n;
    
    int a=1, b=2, c=3;
    while (1)
    {
        int res = q(a, b, c);
        if (!res) break;

        if (!q(res, b, c)) 
        {
            a = res;
            continue;
        }
        if (!q(a, res, c))
        {
            b = res;
            continue;
        }
        if (!q(a, b, res))
        {
            c = res;
            continue;
        }

        int nb = q(res, b, c), nc = q(a, res, c);
        a = res, b = nb, c = nc;
    }

    ans(a, b, c);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}