#include <bits/stdc++.h>
#pragma GCC Optimize("02")

using namespace std;

void Solve()
{
    int n; cin >> n;
    int a[n+1];
    a[0] = 1;
    for (int i=1; i<=n; i++) cin >> a[i];
    long long ans = 0;
    for (int i=1; i<=n; i++) ans += max(0, a[i]-a[i-1]);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        Solve();
}

