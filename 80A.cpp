#include <bits/stdc++.h>

using namespace std;

vector <int> primes;

bool isPrime(int n)
{
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0) return 0;
    }
    return n>=2;
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i=2; i<=50; i++)
    {
        if (isPrime(i)) primes.push_back(i);
    }
    auto it = find(primes.begin(), primes.end(), n), it2 = find(primes.begin(), primes.end(), m);
    if (it2 != primes.end())
    {
        if (it2-primes.begin()-1 == it-primes.begin())
        {
            cout << "YES";
        }
        else cout << "NO";
    }
    else cout << "NO";
}