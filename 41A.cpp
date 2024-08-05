#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int cnt=0;
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i=0; i<s1.length(); i++){
		if (s1[i] != s2[s2.length()-i-1]) cnt++;
	}
	if (cnt==0) cout << "YES";
	else cout << "NO";
}