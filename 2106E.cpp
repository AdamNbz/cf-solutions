#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

int par[(int)(2e5+5)];

void skibidi()
{
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i], par[a[i]] = i+1;
    
    while (q--)
    {
        int l, r, x; cin >> l >> r >> x;
        if (par[x] < l || par[x] > r) 
        {
            cout << -1 << ' ';
            continue;
        }

        int L = l, R = r, cnt1 = 0, cnt2 = 0, mi = 0, mg = 0, m = 0;
        while (L <= R)
        {
            int mid = L+R>>1;
            if (mid == par[x]) break;

            if (mid < par[x]) 
            {
                if (a[mid-1] < x) cnt1++;
                else mi++, m++;
                L = mid+1;
            }
            else 
            {
                if (a[mid-1] > x) cnt2++;
                else mg++, m++;
                R = mid-1;
            }
        }
        
        cout << (mi > x-1-cnt1 || mg > n-x-cnt2 ? -1 : m+llabs(mi-mg)) << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}