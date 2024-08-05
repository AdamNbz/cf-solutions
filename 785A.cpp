#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ld long double
#define f0(i,n) for(int i=0; i<n; i++)
#define f1(i,n) for(int i=1; i<=n; i++)

const int MAXN = 1e8;

using namespace std;

void solve(int &ans, string &s){
	getline(cin, s);
	if (s == "Tetrahedron") ans += 4;
	if (s == "Cube") ans += 6;
	if (s == "Octahedron") ans += 8;
	if (s == "Dodecahedron") ans += 12;
	if (s == "Icosahedron") ans += 20;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans=0;
    string s;
    getline(cin, s);
    f0(i,n) {
    	solve(ans, s);
	}
	cout << ans;
}