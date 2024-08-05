#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int n, x; cin >> n >> x;
    int ans=1, cnt=2;
    while (cnt < n)
    {
        cnt += x;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}