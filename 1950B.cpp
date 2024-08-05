#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

void Solve()
{
    int n; cin >> n;
    vector <vector <char>> a(2*n, vector<char>(2*n));
    char add = '#';
    int i, j;
    for (i=0; i<2*n; i+=2)
    {
        for (j=0; j<2*n; j+=2)
        {
            if ((i/2)%2==0)
            {
                if ((j/2)%2==0) a[i][j] = a[i][j+1] = a[i+1][j+1] = a[i+1][j] = '#';
                else a[i][j] = a[i][j+1] = a[i+1][j+1] = a[i+1][j] = '.';
            }
            else
            {
                if ((j/2)%2==0) a[i][j] = a[i][j+1] = a[i+1][j+1] = a[i+1][j] = '.';
                else a[i][j] = a[i][j+1] = a[i+1][j+1] = a[i+1][j] = '#';
            }
        }
    }
    for (int i=0; i<2*n; i++)
    {
        for (int j=0; j<2*n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
        Solve();
}
