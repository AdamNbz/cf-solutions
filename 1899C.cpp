#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void Solve()
{
    int n; cin >> n;
    vector <int> a;
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    int ans = 0, dp[n*2];
    for (int i=0; i<n-1; i++)
    {
        int sum=a[i];
        for (int j=1; j<n; j++)
        {
            if ((abs(a[i]) % 2) != (abs(a[j]) % 2)) sum += a[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
