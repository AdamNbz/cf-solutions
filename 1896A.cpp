#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;
using ll = long long;

void Solve()
{
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    if (a[0] != 1) cout << "no" << endl;
    else cout << "yes" << endl;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}