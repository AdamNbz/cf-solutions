#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n];
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        //a[0]
        if (a[0] != a[1] && a[0]!=a[2] ) 
            cout << 1 << "\n";
        //a[1]
        else if ( a[0] != a[1] && a[1]!=a[2] ) 
            cout << 2 << "\n";
        else for (int i=2;i<n;++i){
            if (a[i] != a[i-1]) 
            {
                cout << i+1  << "\n";
                break;
            }
        }
    }
}