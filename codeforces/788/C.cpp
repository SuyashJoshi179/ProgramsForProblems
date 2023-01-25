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

int a[M], b[M], c[M];



void solve()
{
    int m, n, d, e;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> a[i];
    fo(i, n) cin >> b[i];
    fo(i, n) cin >> c[i];
    map<int, int> ma, mb;
    fo(i, n) {
        ma[a[i]] = i;
    }
    fo(i, n) {
        if(a[i] == b[i]) c[i] = a[i];
    }
    vector<bool> vis(n, false);
    int ans = 1;
    int j = 0;
    // while(true) {
    //     bool flag = true;
    //     Fo(i, j, n) {
    //         if(c[i] == 0) {
    //             ans <<= 1;
    //             ans %= mod;
    //             c[i] = a[i];
    //             bool f = true;
    //             e = mb[a[i]];
    //             while(c[e] == 0) {
    //                 c[e] = a[e];
    //                 e = mb[a[e]];
    //             }
    //             j = i+1;
    //             flag = false;
    //             continue;
    //         }
    //     }
    //     if(flag) break;
    // }

    fo(i, n) {
        if(vis[i] == false) {
            vis[i] = true;
            bool f = (c[i] == 0);
            int init = ma[b[i]];
            while(init != i) {
                if(c[init] != 0) f = false;
                vis[init] = true;
                init = ma[b[init]];
            }
            if(f) {
                ans <<= 1;
                ans %= mod;
            }
        }
    }

    // fo(i, n) cout<<c[i]<<" ";
    // cout<<ln;
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