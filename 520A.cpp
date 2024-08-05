#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	short n;
	cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	sort (s.begin(),s.end());
	set <int> c;
	long tong=0;
	for (int i=0; i<s.length(); i++){
		c.insert((int)s[i]);
	}
	if (c.size() != 26) cout << "NO";
	else cout << "YES";
}