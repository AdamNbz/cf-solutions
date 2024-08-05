#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector <int> cnt(n+1);
	int t=2;
	while (t--)
	{
		int x; cin >> x;
		for (int i=1; i<=x; i++)
		{
			int tmp;
			cin >> tmp;
			cnt[tmp]++;
		}
	}
	bool ans = true;
	for (int i=1; i<=n; i++)
	{
		if (cnt[i] == 0) ans = false;
	}
	if (ans) cout << "I become the guy.";
	else cout << "Oh, my keyboard!";
}