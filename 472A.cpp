#include <bits/stdc++.h>

using namespace std;

bool isComposite(int n)
{
    int cnt = 0;
    for (int i=1; i<n; i++)
    {
        if (n%i==0) cnt++;
    }
    return cnt >= 2;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i=1; i<n; i++)
    {
        for (int j=1; j<n; j++)
        {
            if (i+j == n && isComposite(i) && isComposite(j)) 
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }
}