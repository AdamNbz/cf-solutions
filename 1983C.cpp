#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const ll mod = (ll)(1e9+7);
const int N = 2e5+20;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, tot, ord[3], ans[6], val[3][N];

void sol()
{
    tot = 0;

    cin >> n;

    for (int i=0; i<3; i++)
        for (int j=0; j<n; j++)
        {
            cin >> val[i][j];
            if (i == 0) tot += val[i][j];
        }

    iota(ord, ord+3, 0);

    bool flag = false;

    do
    {
        int cur = 0, p = 0, s = 0;
        vi v;

        while (p < n)
        {
            s += val[ord[cur]][p];
            if (3*s >= tot)
            {
                v.push_back(p);
                cur++;
                s = 0;
            }
            if (cur == 3) break;

            p++;
        }

        if (cur == 3)
        {
            v[2] = n-1;
            int l = 0;
            for (int i=0; i<3; i++)
            {
                ans[2*ord[i]] = l;
                ans[2*ord[i]+1] = v[i];
                l = v[i]+1;
            }
            for (int i=0; i<6; i++) cout << ans[i]+1 << " ";
            cout << "\n";

            flag = 1;
            break;
        }
    } while (next_permutation(ord, ord+3));
    if (!flag) cout << "-1\n";
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}



