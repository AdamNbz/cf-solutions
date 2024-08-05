#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++)
    {
        if (a[i] == k) 
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        Solve();
    }
}