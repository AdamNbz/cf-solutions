#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long n;
    cin >> n;
    vector <int> magnet;
    for (long i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        magnet.push_back(tmp);
    }
    int ans=0, i=0;
    while (i<n){
        if (magnet[i] != magnet[i+1]) ans++;
        ++i;
    }
    cout << ans;
}