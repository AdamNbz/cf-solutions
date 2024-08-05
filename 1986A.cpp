#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

void sol()
{
    //My solution:
    vector<int> axis(3);
    for (int i=0; i<3; i++) cin >> axis[i];
    sort(axis.begin(), axis.end());
    cout << abs(axis[0]-axis[1]) + abs(axis[1]-axis[1]) + abs(axis[2]-axis[1]) << '\n';
    //Solution: calculate the difference between the maximum and the minimum point
    //int a, b, c; cin >> a >> b >> c;
    //cout << max({a, b, c}) - min({a, b, c}) << '\n';

}
int main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}
