#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

void Solve()
{
    int n; cin >> n;
    vector <int> a;
    for (int i=0; i<2*n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), cmp);
    int x=0, y=0;
    for (int i=1; i<n; i++) x += a[i-1] - a[i];
    for (int i=n+1; i<2*n; i++) y += a[i-1] - a[i];
    cout << x+y << endl;
    vector <pair <int, int>> b;
    for (int i=0; i<n; i++)
    {
        b.push_back({a[i], a[n+i]});
    }
    for (auto p: b)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
