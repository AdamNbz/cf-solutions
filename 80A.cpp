#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

bool is_prime(int n)
{
    for (int i=2; i*i<=n; i++) if (n%i==0) return 0;
    return n>=2;
}

void skibidi()
{
    int n, m; cin >> n >> m;
    vector<int> primes;
    for (int i=2; i<=50; i++) if (is_prime(i)) primes.push_back(i);

    auto idx = lower_bound(primes.begin(), primes.end(), n)-primes.begin();
    if (primes[idx+1] != m) 
    {
        cout << "NO";
        return;
    }
    cout << "YES";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}