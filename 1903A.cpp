#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void Solve()
{
    int n, k; cin >> n >> k;
    int a[n]; for (int i=0; i<n; i++) cin >> a[i];
    cout << ((k > 1 || is_sorted(a, a+n)) ? "YES" : "NO") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
