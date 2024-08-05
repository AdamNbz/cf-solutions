#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Solve()
{
    string time; cin >> time;
    cin.ignore();
    if (time[0] == '0')
    {
        if (time[1] == '0') cout << "12" << time[2] << time[3] << time[4] << " AM";
        else cout << time << " AM";
    }
    else if (time[0] == '1')
    {
        if (time[1] >= '0' && time[1] < '2') cout << time << " AM";
        else if (time[1] == '2') cout << time << " PM";
        else cout << "0" << (int)(time[1]-'0')-2 << time[2] << time[3] << time[4] << " PM";
    }
    else if (time[0] == '2')
    {
        if (time[1] == '0') cout << "08" << time[2] << time[3] << time[4] << " PM";
        if (time[1] == '1') cout << "09" << time[2] << time[3] << time[4] << " PM";
        if (time[1] == '2') cout << "10" << time[2] << time[3] << time[4] << " PM";
        if (time[1] == '3') cout << "11" << time[2] << time[3] << time[4] << " PM";
    }
    cout << endl;
}

int main()
{
    init();
    int t; cin >> t;
    while (t--)
        Solve();
}
