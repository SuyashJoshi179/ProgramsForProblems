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
int dp[M];
void pre() {
    int m = 1e3 + 2;
    fo(i, m) {
        dp[i] = 2e9;
    }
    dp[1] = 0;
    int t;
    Fo(i, 1, m) {
        Fo(j, i, 0) {
            t = i + i/j;
            if(t < m) dp[t] = min(dp[t], dp[i] + 1);
            else break;
        }
    }
    // fo(i, m) cout<<dp[i]<<ln;
}

void solve()
{
    int m, n, a, b, c, d, k;
    string s1, s2;
    cin >> n >> k;
    fo(i, n) cin >> ar[i];
    fo(i, n) cin >> ar1[i];
    fo(i, n) ar[i] = dp[ar[i]];
    // fo(i, n) cout << ar[i] << " ";
    // cout<<ln;
    k = min(k, 13 * n); // ***** Time Reducer Line *****
    vector<int> v(k+1, -1);
    v[0] = 0;
    int ans = 0;
    fo(i, n) {
        if(ar[i] == 0) ans += ar1[i];
        else {
            Fo(j, max(k - ar[i], -1), -1) {
                if(v[j] != -1) v[j + ar[i]] = max(v[j + ar[i]], v[j] + ar1[i]);
            }
            v[ar[i]] = max(v[ar[i]], ar1[i]);
        } 
    }
    cout<<ans + *max_element(all(v))<<ln;

}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;
    pre();
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}