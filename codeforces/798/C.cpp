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

int dfs(int root, vvi &v, int par = -1) {
    // dbg2(par, root);
    if(v[root].size() <= 2) {
        return v[root].size();
    } else {
        int a = -1, b = -1;
        for(int i: v[root]) {
            if(i != par) {
                if(a == -1) a = i;
                else b = i;
            }
        }
        a = dfs(a, v, root);
        b = dfs(b, v, root);
        return min(a, b)+2;
    }
}

void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    vvi v(n);
    fo(i, n-1) {
        cin >> a >> b;
        // dbg2(a, b);
        v[a-1].pb(b-1);
        v[b-1].pb(a-1);
    }
    v[0].pb(-1);
    a = dfs(0, v);
    cout<<n - a<<ln;
    

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