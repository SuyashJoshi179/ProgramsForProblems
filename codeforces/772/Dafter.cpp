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



void solve()
{
    int m, n, a, b, c, d, p;
    string s1, s2;
    cin >> n >> p;
    fo(i, n) cin >> ar[i];
    sort(ar, ar+n);
    set<int> useful;
    fo(i, n) {
        bool flag = true;
        a = ar[i];
        while(a > 0) {
            if(useful.find(a) != useful.end()) {
                flag = false;
                break;
            }
            if(a & 1) { // ___1
                a >>= 1;
            } else if((a & 3) == 0) { // ____00
                a >>= 2;
            } else break;
        }
        if(flag) useful.insert(ar[i]);
    }

    int dp[max(p+1, 30)] = {0};
    for(auto i: useful) {
        // cout<<i<<":"<<(int)log2(i)+1<<" ";
        dp[(int)log2(i) + 1]++;
    }
    // cout<<ln;
    int ans = dp[0] + dp[1];
    Fo(i, 2, p+1) {
        dp[i] += dp[i-1] + dp[i-2];
        dp[i] %= mod;
        ans += dp[i];
        ans %= mod;
    }
    // fo(i, p+1) cout<<dp[i]<<" ";
    // cout<<ln;
    cout<<ans<<ln;
}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}