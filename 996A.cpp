#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[5] = {100, 20, 10, 5, 1};
    int cnt = 0;
    for (int i=0; i<5; i++)
    {
        cnt += n/a[i];
        n %= a[i];
    }
    cout << cnt;
}