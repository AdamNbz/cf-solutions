#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int x, y; cin >> x >> y;
    string s; cin >> s;
    int cntU=0, cntD=0, cntR=0, cntL=0;
    for (auto i: s)
    {
        cntU += i == 'U';
        cntD += i == 'D';
        cntR += i == 'R';
        cntL += i == 'L';
    }
    if (((x > 0 && y > 0) && (cntR == x && cntU == y)) || ((x > 0 && y < 0) && (cntR == x && cntD == abs(y))) || ((x < 0 && y > 0) && (cntL == abs(x) && cntU == y)) || ((x < 0 && y < 0) && (cntL == abs(x) && cntD == abs(y)))) cout << "YES";
    else cout << "NO";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}