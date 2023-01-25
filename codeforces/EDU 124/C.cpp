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

int ar[M];

int ar1[M];

void solve()
{
    ll m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar[i];
    fo(i, n) cin >> ar1[i];
    a = abs(ar[0] - ar1[0]);
    fo(i, n) {
        if(abs(ar[0] - ar1[i]) < a) {
            a = abs(ar[0] - ar1[i]);
        }
    }
    

    b = abs(ar[n-1] - ar1[0]);
    fo(i, n) {
        if(abs(ar[n-1] - ar1[i]) < b) {
            b = abs(ar[n-1] - ar1[i]);
        }
    }

    c = abs(ar[0] - ar1[0]);
    fo(i, n) {
        if(abs(ar[i] - ar1[0]) < c) {
            c = abs(ar[i] - ar1[0]);
        }
    }

    d = abs(ar[0] - ar1[n-1]);
    fo(i, n) {
        if(abs(ar[i] - ar1[n-1]) < d) {
            d = abs(ar[i] - ar1[n-1]);
        }
    }
    ll aa = abs(ar[0] - ar1[0]);
    ll bb = abs(ar[n-1] - ar1[n-1]);
    ll ab = abs(ar[0] - ar1[n-1]);
    ll ba = abs(ar[n-1] - ar1[0]);
    ll ans[] = {aa + bb, ab + ba, aa + b + d, ab + b + c, ba + a + d, bb + a + c, a + b + c + d};
    sort(ans, ans+7);
    cout<<ans[0]<<ln;
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