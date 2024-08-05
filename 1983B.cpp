#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const ll mod = 3;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

int n, m;

void sol()
{
    //input:
    cin >> n >> m;
    vii grid_a(n, vi(m));
    vii grid_b(n, vi(m));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            char x; cin >> x;
            grid_a[i][j] = x - '0';
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            char x; cin >> x;
            grid_b[i][j] = x - '0';
        }
    }

    for (int i = n-1; i >= 1; --i)
    {
        for (int j = m-1; j >= 1; --j)
        {
            if (grid_a[i][j] != grid_b[i][j]) {
                int res = (grid_b[i][j]-grid_a[i][j]+3)%3;
                grid_a[i][j] = grid_b[i][j];
                grid_a[i-1][j] = (grid_a[i-1][j]+2*res)%3;
                grid_a[i][j-1] = (grid_a[i][j-1]+2*res)%3;
                grid_a[i-1][j-1] = (grid_a[i-1][j-1]+res)%3;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (grid_a[i][0] != grid_b[i][0])
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i=0; i<m; i++) {
        if (grid_a[0][i] != grid_b[0][i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}


