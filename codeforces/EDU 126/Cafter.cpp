#include <bits/stdc++.h>
#include <random>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pl>> vvpi;
typedef vector<vector<pl>> vvpl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
ll MOD = 998244353;
const int mod = 1'000'000'007;
const int M = 200002;
double eps = 1e-12;
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define ln "\n"
#define dbg(x) cout << #x << "=" << x << ln
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << ln
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define sz(x) (x).size()
#define iterate(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

int ar[M*2];



void solve()
{
    ll m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar[i];
    int mx = *max_element(ar, ar+n);
    ll c1 = 0, c2 = 0;
    fo(i, n) {
        a = mx - ar[i];
        if(a%2) c1++;
        c2 += a/2;
    }
    ll ans = c1*2 - 1;
    c2 -= c1 - 1;
    c2 = max(c2, 0ll);
    
    // if(c2 == 0) {
    //     cout<<ans<<ln;
    //     return;
    // }
    c2 *= 2;
    ans += (c2/3)*2;
    if(c2%3) ans += 1;
    
    mx = *max_element(ar, ar+n)+1;
    c1 = 0, c2 = 0;
    fo(i, n) {
        a = mx - ar[i];
        if(a%2) c1++;
        c2 += a/2;
    }
    ll ans1 = c1*2 - 1;
    c2 -= c1 - 1;
    c2 = max(c2, 0ll);
    
    // if(c2 == 0) {
    //     cout<<ans<<ln;
    //     return;
    // }
    c2 *= 2;
    ans1 += (c2/3)*2;
    if(c2%3) ans1 += 1;

    cout<<min(ans, ans1)<<ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}