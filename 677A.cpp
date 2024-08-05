#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long n, h, ans=0;
	vector <int> A;
	cin >> n >> h;
	A.resize(n);
	for (int i=0; i<n; i++){
		cin >> A[i];
	}
	for (int i=0; i<n; i++){
		if (A[i] <= h) ans += 1;
		else ans += 2;
	}
	cout << ans;
}