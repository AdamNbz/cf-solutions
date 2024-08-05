#include <bits/stdc++.h>
 
using namespace std;
 
struct Room{
    int p;
    int q;
};
 
int main()
{
    int n;
    cin >> n;
    vector <Room> A;
    A.resize(n);
    for (int i=0; i<n; i++){
        cin >> A[i].p >> A[i].q;
    }
    int ans=0;
    for (int i=0; i<n; i++){
        if (A[i].p != A[i].q) {
            int tmp = A[i].q - A[i].p;
            if (tmp >= 2) ans++;
        }
    }
    cout << ans;
    return 0;
}