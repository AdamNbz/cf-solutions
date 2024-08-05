#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int p; cin >> p;
    int minn = p, maxn = p, cnt=0;
    for (int i=2; i<=n; i++)
    {
        cin >> p;
        if (p < minn)
        {
            minn = p;
            cnt++;
        }
        if (p > maxn)
        {
            maxn = p;
            cnt++;
        }
    }
    cout << cnt;
}
