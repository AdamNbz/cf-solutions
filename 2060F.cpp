/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define el '\n'
#define pb push_back
#define eb emplace_back
#define io() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define mask(i) (1LL << (i))
#define getbit(mask, i) (((mask) >> (i)) & 1)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<ll> v64;
typedef vector<vector<ll> > vv64;
typedef vector<p32> vp32;
typedef vector<vector<p32> > vvp32;
typedef vector<p64> vp64;
typedef vector<vector<p64> > vvp64;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
typedef vector<vs > vvs;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }
int parity(ull mask) { return __builtin_parityll(mask); }

const ll MOD = 998244353;
const ll inf = numeric_limits<ll>::max();

static vector<pair<int,ll>> allTests;
static int T = 0;
static int maxK = 0;

static const int MAXK = 100000;
static int spf[MAXK + 1];

static int polyDeg [MAXK+1];
static int polyCoeff [MAXK+1][20];

static const int MAXF = 40;
static int fact[MAXF], invFact[MAXF];

static const int MAXP = 16;
static v32 sumPowVal[MAXP + 1];

static bool preprocessed = 0;

inline int addmod(int a, int b) {
    int r = a + b;
    if(r >= (int)MOD) r -= MOD;
    return r;
}
inline int submod(int a, int b) {
    int r = a - b;
    if(r < 0) r += MOD;
    return r;
}
inline int mulmod(ll a, ll b) 
{
    ll r = a * b;
    r %= MOD;
    return (int)r;
}
int modExp(int base, ll exp) {
    int res = 1;
    while(exp > 0) {
        if(exp & 1) res = mulmod(res, base);
        base = mulmod(base, base);
        exp >>= 1;
    }
    return res;
}
int invmod(int x) 
{
    return modExp(x, MOD-2);
}

void buildSpf(int n) 
{
    for(int i=2; i<=n; i++)
    {
        spf[i] = 0;
    }
    for(int i=2; i<=n; i++)
    {
        if(!spf[i]) 
        {
            spf[i] = i;
            if((long long)i*i <= n) 
            {
                for(int j=i*i; j<=n; j+=i) 
                {
                    if(!spf[j]) spf[j] = i;
                }
            }
        }
    }
}

void buildFactorials() 
{
    fact[0] = 1;
    for(int i=1; i<MAXF; i++)
    {
        fact[i] = mulmod(fact[i-1], i);
    }
    invFact[MAXF-1] = invmod(fact[MAXF-1]);
    for(int i=MAXF-2; i>=0; i--)
    {
        invFact[i] = mulmod(invFact[i+1], (i+1));
    }
}

v32 buildBinomialPoly(int e) 
{
    vector<int> poly(1, 1);
    for(int i=0; i<e; i++)
    {
        vector<int> newPoly(poly.size()+1, 0);
        for(int p=0; p<(int)poly.size(); p++)
        {
            int c = poly[p];
            newPoly[p+1] = addmod(newPoly[p+1], c);
            ll tmp = (ll)c * i;
            tmp %= MOD;
            newPoly[p] = addmod(newPoly[p], (int)tmp);
        }
        poly.swap(newPoly);
    }
    if(e > 0) 
    {
        int invF = invFact[e];
        for(auto & c: poly) 
        {
            c = mulmod(c, invF);
        }
    }
    return poly;
}

v32 polyMul(const v32 &A, const v32 &B) 
{
    vector<int> C(A.size() + B.size() - 1, 0);
    for(int i=0; i<(int)A.size(); i++)
    {
        for(int j=0; j<(int)B.size(); j++)
        {
            int val = mulmod(A[i], B[j]);
            C[i+j] = addmod(C[i+j], val);
        }
    }
    return C;
}

void buildAllPolynomials(int mxK) 
{
    polyDeg[1] = -1;
    for(int x=2; x<=mxK; x++)
    {
        int tmp = x;
        vector<int> polyP(1,1);
        while(tmp > 1)
        {
            int prime = spf[tmp];
            int e=0;
            while(spf[tmp] == prime)
            {
                e++;
                tmp /= prime;
            }
            auto binPoly = buildBinomialPoly(e);
            polyP = polyMul(polyP, binPoly);
        }
        int deg = (int)polyP.size()-1;
        polyDeg[x] = deg;
        for(int i=0; i<=(int)deg; i++)
        {
            polyCoeff[x][i] = polyP[i];
        }
        for(int i=deg+1; i<20; i++)
        {
            polyCoeff[x][i] = 0;
        }
    }
}

void precomputeSumPowerTables() 
{
    for(int p=0; p<=MAXP; p++)
    {
        sumPowVal[p].resize(p+2);
        long long running=0;
        for(int m=0; m<=p+1; m++)
        {
            if(m==0) 
            {
                running=0;
            } else 
            {
                long long val=1, mm=m;
                for(int _=0; _<p; _++)
                {
                    val=(val*mm)%MOD;
                }
                running=(running+val)%MOD;
            }
            sumPowVal[p][m] = (int)running;
        }
    }
}

int getSumPower(ll n, int p) 
{
    if(n <= p+1) 
    {
        return sumPowVal[p][ (int)n ];
    }
    int deg = p+1;
    vector<int> pref(deg+2, 1), suf(deg+2, 1);
    for(int i=1; i<=deg+1; i++)
    {
        ll diff = (n - (i-1))%MOD;
        if(diff<0) diff+=MOD;
        pref[i] = mulmod(pref[i-1], (int)diff);
    }
    for(int i=deg+1; i>=0; i--)
    {
        if(i==deg+1) suf[i] = 1;
        else 
        {
            ll diff = (n - i)%MOD;
            if(diff<0) diff+=MOD;
            suf[i] = mulmod(suf[i+1], (int)diff);
        }
    }
    static bool denReady=false;
    static int denInv[MAXP+1][MAXP+2];
    if(!denReady) 
    {
        for(int pp=0; pp<=MAXP; pp++)
        {
            int dd=pp+1;
            for(int j=0; j<=dd; j++)
            {
                ll prod=1;
                for(int m=0; m<=dd; m++)
                {
                    if(m==j) continue;
                    ll dif = (ll)j - m;
                    dif = (dif % MOD + MOD)%MOD;
                    prod=(prod*dif)%MOD;
                }
                denInv[pp][j] = invmod((int)prod);
            }
        }
        denReady=true;
    }
    int ans=0;
    for(int j=0; j<=deg; j++)
    {
        int y = sumPowVal[p][j];
        ll term = 1LL*pref[j]*suf[j+1] % MOD;
        term = (term * denInv[p][j]) % MOD;
        term = (term * y) % MOD;
        ans = addmod(ans, (int)term);
    }
    return ans;
}

void globalPreprocess() 
{
    buildSpf(maxK);
    buildFactorials();
    buildAllPolynomials(maxK);
    precomputeSumPowerTables();
    preprocessed = true;
}

static int crrTestIndex = 0;

void sol()
{
    int k = allTests[crrTestIndex].fi;
    ll n = allTests[crrTestIndex].se;
    crrTestIndex++;

    static int sumPw[17]; 
    for(int p=0; p<=16; p++)
    {
        sumPw[p] = getSumPower(n, p);
    }

    for(int x=1; x<=k; x++)
    {
        if(x==1)
        {
            cout << (n%MOD) << ((x==k) ? '\n' : ' ');
            continue;
        }

        int d = polyDeg[x];
        ll ans=0;
        for(int p=0; p<=d; p++)
        {
            ans += 1LL * polyCoeff[x][p] * sumPw[p];
        }
        ans %= MOD;
        cout << ans << ((x==k) ? '\n' : ' ');
    }
}

int32_t main()
{
    io();
    cin >> T;
    allTests.resize(T);
    for (int i=0; i<T; i++)
    {
        ll n; int k; cin >> k >> n;
        allTests[i] = {k, n};
        if (k > maxK) maxK = k;
    }

    globalPreprocess();

    for (int i=0; i<T; i++) sol();

    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}