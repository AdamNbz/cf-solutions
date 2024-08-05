#include <bits/stdc++.h>

using namespace std;

void runCase(){
	string s;
	cin >> s;
	cout << (s[0]-'0') + (s[2]-'0') << "\n";
}

int main(){
	int t;
	cin >> t;
	while (t--){
		runCase();
	}
}