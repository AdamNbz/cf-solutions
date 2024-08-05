#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

bool in(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void sol()
{
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int mxN = 0;
            for (int k=0; k<4; k++)
            {
                int i2 = i+dx[k], j2 = j+dy[k];
                if (in(i2, j2)) mxN = max(mxN, a[i2][j2]);
            }
            a[i][j] = min(a[i][j], mxN);
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}
