#include <bits/stdc++.h>
#pragma GCC optimize ("03")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;
    double p[n];
    double sum=0;
    for (int i=0; i<n; i++)
    {
        cin >> p[i];
        p[i] = p[i]/100;
        sum += p[i];
    }
    cout << fixed << setprecision(12) << sum*100/n;

}
