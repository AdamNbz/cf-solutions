#include <bits/stdc++.h>

using namespace std;

bool distint(int y)
{
    set <int> distint;
    while (y>0)
    {
        distint.insert(y%10);
        y /= 10;
    }
    if (distint.size() != 4) return 0;
    return 1;
}

int main()
{
    int y; cin >> y;
    y++;
    bool check = 1;
    while (check)
    {
        if (distint(y)) 
        {
            cout << y;
            check = 0;
        }
        y++;
    }
}