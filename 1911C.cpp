#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;
    int a[n+5];
    for (int i=0; i<n; i++) cin >> a[i];
    sort (a, a+n);
    int s = 0;
    for (int i=0; i<n; i+=2)
    {
        if (a[i] != a[i+1]) s += (a[i+1] - a[i]);
    }
    cout << s;
}
