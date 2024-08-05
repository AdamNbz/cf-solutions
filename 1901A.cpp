#include <bits/stdc++.h>
#pragma GCC Optimize("02")

using namespace std;

void Solve()
{
    int n, x; cin >> n >> x;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    vector <int> dist;
    dist.push_back(a[0]-0);
    for (int i=1; i<n; i++)
    {
        dist.push_back(a[i] - a[i-1]);
    }
    dist.push_back(2*(x-a[n-1]));
    sort(dist.begin(), dist.end());
    cout << dist.back() << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        Solve();
}
