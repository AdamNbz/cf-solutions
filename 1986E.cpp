#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;

const int N = 1e5+5,
const ll inf = 3e18+20;

int n, k, a[N];
ll pref[N], suff[N];


void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}


void sol()
{
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.begin()+n, [](int i, int j)
         {
            if (i%k == j%k) return i < j;
            return (i%k) < (j%k);
         });

}

int main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}


