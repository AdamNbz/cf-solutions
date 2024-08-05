#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;

int main(){
	string s, s1 = "", s2 = "+";
	getline(cin, s);
	if (s.length()<2) cout << s;
	else {
		for (int i=0; i<s.length(); i++){
			if (s[i] == '+') s.erase(i, 1);
		}
		sort(s.begin(), s.end());
		for (int i=0; i<s.length(); i++){
			s1 += s[i] + s2;
		}
		s1.erase(s1.length()-1, 1);
		cout << s1;
	}
}
