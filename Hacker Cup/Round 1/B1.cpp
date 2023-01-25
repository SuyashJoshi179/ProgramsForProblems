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
const ll mod = 1'000'000'007;
const int M = 500002;
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

ll A[M], B[M], X[M], Y[M];



void solve()
{
    ll m, n, a, b, c, d, q;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> A[i] >> B[i];
    cin >> q;
    fo(i, q) cin >> X[i] >> Y[i];
    ll sa2 = 0, sb2 = 0, sa = 0, sb = 0;
    fo(i, n) {
        sa += A[i];
        sb += B[i];
        sa2 += A[i]*A[i];
        sb2 += B[i]*B[i];
        sa %= mod;
        sb %= mod;
        sa2 %= mod;
        sb2 %= mod;
    }
    // cout<<ln;
    ll ans = 0;
    fo(i, q) {
        a = X[i]*sa;
        a %= mod;
        a *= 2;
        a %= mod;
        b = Y[i]*sb;
        b %= mod;
        b *= 2;
        b %= mod;
        a += b;
        a %= mod;
        c = X[i]*X[i];
        c %= mod;
        d = Y[i]*Y[i];
        d %= mod;
        c = ((c + d)*n)%mod;
        ans += (sa2 + sb2 - a + c + mod)%mod;
        if(ans >= mod) ans -= mod;
        // cout<<(sa2 + sb2 - a + c + mod)%mod<<ln;
    }
    cout<<ans<<ln;

}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout<<"Case #"<<it<<": ";
        solve();
    }
    return 0;
}