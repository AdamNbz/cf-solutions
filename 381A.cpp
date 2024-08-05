#include <bits/stdc++.h>
#pragma GCC optimize ("03")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;
    int a[n+1];
    for (int i=1; i<=n; i++) cin >> a[i];
    int s1=0, s2=0, l=1, r=n, i=1;
    while (l <= r)
    {
        if (i%2==1)
        {
            if (a[l] >= a[r]) s1 += a[l++];
            else s1 += a[r--];
        }
        else
        {
            if (a[l] >= a[r]) s2 += a[l++];
            else s2 +=  a[r--];
        }
        i++;
    }
    cout << s1 << " " << s2;
}
