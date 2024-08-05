#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, n, w;
	cin >> k >> n >> w;
	int price=0;
	for (int i=1; i<=w; i++) price += i*k;
	if (price > n) cout << price - n;
	else cout << 0;
}