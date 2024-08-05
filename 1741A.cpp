#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ld long double
#define f0(i,n) for(int i=0; i<n; i++)
#define f1(i,n) for(int i=1; i<=n; i++)

const int MAXN = 1e8;

using namespace std;

void solve(){
	string a, b;
	cin >> a >> b;
	int len1 = a.length(), len2 = b.length(), cntXa=0, cntXb=0;
	f0(i, len1) {
		if (a[i] == 'X') cntXa++;
	}
	f0(i, len2) {
		if (b[i] == 'X') cntXb++;
	}
	switch (a[len1-1]){
		case 'L':
			if (b[len2-1] == 'L') {
				if (cntXa == cntXb) {
					cout << "=" << endl;
					break;
				}
				else if (cntXa < cntXb) {
					cout << "<" << endl;
					break;
				}
				else {
					cout << ">" << endl;
					break;
				}
			}
			else {
				cout << ">" << endl;
				break;
			}
		case 'M':
			if (b[len2-1] == 'L') {
				cout << "<" << endl;
				break;
			}
			else if (b[len2-1] == 'M'){
				if (cntXa == cntXb) {
					cout << "=" << endl;
					break;
				}
				else if (cntXa < cntXb) {
					cout << "<" << endl;
					break;
				}
				else {
					cout << ">" << endl;
					break;
				}
			}
			else {
				cout << ">" << endl;
				break;
			}
		case 'S':
			if (b[len2-1] == 'S') {
				if (cntXa == cntXb) {
					cout << "=" << endl;
					break;
				}
				else if (cntXa < cntXb) {
					cout << ">" << endl;
					break;
				}
				else {
					cout << "<" << endl;
					break;
				}
			}
			else {
				cout << "<" << endl;
				break;
			}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    f0(i, n){
    	solve();
	}
}