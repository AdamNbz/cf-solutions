#include <bits/stdc++.h>
#pragma GCC optimize ("03")

using namespace std;

int main()
{
    int n; cin >> n;
    int cap = 0, still=0;
    while (n--)
    {
        int a, b; cin >> a >> b;
        still = still - a + b;
        cap = max(cap, still);
    }
    cout << cap;
}

