#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector <int> a;
	for (int i=0; i<n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	int ans = n;
	for (int i=0; i<n; i++){
		if (a[i] == 0 || a[i] < a[k-1]) ans--;
	}
	cout << ans;
}
