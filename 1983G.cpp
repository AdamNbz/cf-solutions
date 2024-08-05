#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

const ll mod = (ll)(1e9 + 7);
const int MAXN = 500005;
const int LOG = 20;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

int n, q;
vector<int> adj[MAXN];
vi a;
int parent[MAXN], level[MAXN];
int euler[2 * MAXN], firstOccurrence[MAXN];
int sparseTable[2 * MAXN][LOG];
bool visited[MAXN];
int timer;

void dfs(int node, int par, int depth) {
    visited[node] = true;
    parent[node] = par;
    level[node] = depth;
    euler[timer] = node;
    firstOccurrence[node] = timer++;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, node, depth + 1);
            euler[timer++] = node;
        }
    }
}

void buildSparseTable(int n) {
    for (int i = 0; i < n; ++i)
        sparseTable[i][0] = euler[i];
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; (i + (1 << j) - 1) < n; ++i) {
            if (level[sparseTable[i][j - 1]] < level[sparseTable[i + (1 << (j - 1))][j - 1]]) {
                sparseTable[i][j] = sparseTable[i][j - 1];
            } else {
                sparseTable[i][j] = sparseTable[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    int left = firstOccurrence[u];
    int right = firstOccurrence[v];
    if (left > right) swap(left, right);
    int length = right - left + 1;
    int log = 31 - __builtin_clz(length); // floor(log2(length))
    if (level[sparseTable[left][log]] < level[sparseTable[right - (1 << log) + 1][log]]) {
        return sparseTable[left][log];
    } else {
        return sparseTable[right - (1 << log) + 1][log];
    }
}

ll pathXorSum(int u, int v) {
    int lca_node = lca(u, v);
    ll result = 0;
    // Traverse from u to LCA
    while (u != lca_node) {
        result += (a[u - 1] ^ u);
        u = parent[u];
    }
    result += (a[lca_node - 1] ^ lca_node);
    // Traverse from v to LCA
    while (v != lca_node) {
        result += (a[v - 1] ^ v);
        v = parent[v];
    }
    return result;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    a.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    memset(visited, false, sizeof(visited));
    timer = 0;
    dfs(1, -1, 0);
    buildSparseTable(timer);

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << pathXorSum(x, y) << "\n";
    }
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
