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

int ar1[M], ar2[M];



void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar1[i];
    fo(i, n) cin >> ar2[i];
    vector<pi> diff(n);
    fo(i, n) diff[i] = {abs(ar1[i] - ar2[i]), i};
    sort(all(diff), greater<pi>());
    a = 0; b = 0;
    for(auto i : diff) {
        if(a > b) {
            b += i.first;
            if(ar1[i.second] > ar2[i.second]) swap(ar1[i.second], ar2[i.second]);
        } else {
            a += i.first;
            if(ar1[i.second] < ar2[i.second]) swap(ar1[i.second], ar2[i.second]);
        }
    }
    ll ans = 0;
    // fo(i, n) cerr<<ar1[i]<<" ";
    // cerr<<ln;
    // fo(i, n) cerr<<ar2[i]<<" ";
    // cerr<<ln;
    fo(i, n-1) {
        Fo(j, i+1, n) ans += (ar1[i] + ar1[j])*(ar1[i] + ar1[j]);
    }
    fo(i, n-1) {
        Fo(j, i+1, n) ans += (ar2[i] + ar2[j])*(ar2[i] + ar2[j]);
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