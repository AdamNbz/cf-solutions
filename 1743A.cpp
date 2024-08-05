#include <bits/stdc++.h>

using namespace std;

int gt (int x)
{
    long tich=1;
    for (int i = 2 ; i<=x ;++i)
    {
        tich=tich*i;
    }
    return tich;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    while (k--)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i = 0 ;i<n; ++i) cin>>a[i];
        cout <<((gt(10-n)/(2*gt(10-n-2))) * 6 )<<endl;
    }
}