#include <bits/stdc++.h>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Solve()
{
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    long long sum = 0;
    sum = accumulate(a, a+n, sum);
    cout << sum << endl;
}

int main()
{
    init();
    int t; cin >> t;
    while (t--)
        Solve();
}
