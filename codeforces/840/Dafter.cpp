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

int ar[101][101];



void solve()
{
    int m, n, a, b, c, d, x, y;
    string s1, s2;
    cin >> n >> a >> b >> x >> y;
    a--; b--; x--; y--;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][n] = 1;
 
    auto valid = [&](int index, int value) -> bool {
        return !(index == a && value != x) && !(index == b && value != y);
    };
 
    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            if (j - i == 1 && (i == 0 || j == n))
                continue;
 
            int next = n - (j - i);
 
            if (valid(i, next))
                dp[i + 1][j] += dp[i][j];
 
            if (j - i > 1 && valid(j - 1, next))
                dp[i][j - 1] += dp[i][j];
        }
    }

    ll ans = 0;
    Fo(i, 1, n) {
        ans += ar[i][i];
        ans %= mod;
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
        solve();
    }
    return 0;
}