/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#ifndef ONLINE_JUDGE
#if defined(__APPLE__)
   #include </Users/home/Documents/nbz_lib/debug.h>
#elif defined(_WIN32) || defined(_WIN64)
   #include <C:/Users/Admin/OneDrive/Documents/nbz_lib/debug.h>
#endif
#else
#define dbg(...) 
#endif

#define nbzzz signed main
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
#define int long long

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

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

void sol()
{
   int n; cin >> n;
   v64 a((n<<1)); for (auto &x: a) cin >> x;
   sort(all(a));

   unordered_set<ll> st;
   st.reserve((n<<2));
   for (auto x: a) st.insert(x);

   v64 odd(a.begin(), a.begin()+n), even(a.begin()+n, a.end());
   ll sum[2] = {accumulate(all(odd), 0ll), accumulate(all(even), 0ll)}, x = sum[1]-sum[0];
   bool chk = (x > 0 && x <= (ll)(1e18) && st.find(x) == st.end());
   if (!chk)
   {
         for (int i=0; i<n; i++) 
         {
            ll y = x-2*(even[i]-odd[n-i-1]);
            if (y > 0 && y <= (ll)(1e18) && st.find(y) == st.end())
            {
                  swap(odd[n-i-1], even[i]);
                  x = y;
                  chk = 1;
                  break;
            }
         }
   }
   if (chk) 
   {
      v64 b;
      b.pb(x);
      for (int i=0; i<n; i++) b.pb(even[i]), b.pb(odd[i]);
      for (auto x: b) cout << x << " ";
      cout << el;
      return;
   }
   
   ll back = a.back();
   v64 bp(a.begin(), a.end()-1);
   ll s = accumulate(all(bp), 0LL), xx = 0, sz = sz(bp);
   bool ok = 0;
   v64 odd2, even2, c(bp.begin() + (sz - n), bp.end());
   ll s2 = accumulate(all(c), 0ll);
   xx = back+2*s2-s;
   if (xx > 0 && xx <= (ll)(1e18) && st.find(xx) == st.end() && xx != back)
   {
      even2 = v64(bp.begin(), bp.begin() + (sz - n));
      even2.pb(xx);
      odd2 = c;
      ok = 1;
   }
   else
   {
      c = v64(bp.begin(), bp.begin()+n);
      s2 = accumulate(all(c), 0ll);
      xx = back+2*s2-s;
      if (xx > 0 && xx <= (ll)(1e18) && st.find(xx) == st.end() && xx != back)
      {
         even2 = v64(bp.begin()+n, bp.end());
         even.pb(xx);
         odd2 = c;
         ok = 1;
      }
   }

   if (!ok)
   {
      v64 b;
      b.pb(x);
      for (int i=0; i<n; i++) b.pb(even[i]), b.pb(odd[i]);
      for (auto x: b) cout << x << " ";
      cout << el;
      return;
   }

   v64 b;
   b.pb(back);
   for (int i=0; i<n; i++) b.pb(even2[i]), b.pb(odd2[i]);
   for (auto x: b) cout << x << " ";
   cout << el;
}

nbzzz()
{
   io();
   int t; cin >> t;
   while (t--) sol();
   cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}