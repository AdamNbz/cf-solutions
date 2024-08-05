#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector <int> A;
	cin >> n;
	A.resize(n);
	for (int i=0; i<n; i++){
		cin >> A[i];
	}
	int cnt=0;
	for (int i=0; i<n; i++){
		if (A[i] == 1) cnt++;
	}
	if (cnt == 0) cout << "EASY";
	else cout << "HARD";
}
