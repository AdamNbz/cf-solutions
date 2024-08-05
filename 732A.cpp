
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, r; cin >> k >> r;
    int ans = 1;
    for (int i=1; i<=9; i++)
    {
        if ((k*i) % 10 == r)
        {
            cout << i;
            break;
        }
        if ((k*i) % 10 == 0)
        {
            cout << i;
            break;
        }
    }
}
