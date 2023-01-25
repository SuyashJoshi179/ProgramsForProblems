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
map<int, vi> ma;
set<int> vis;

pair<ll, bool> mydfs(int x, int prev, int y) {
    bool isNastya = (x == y);
    bool toVis = (vis.find(x) != vis.end());
    ll ans = 0;
    if(ma[x].size() == 1) { // leaf
        return {toVis ? ans : -1, isNastya};
    }

    for(auto i: ma[x]) {
        if(prev == i) continue;
        auto p = mydfs(i, x, y);
        if(p.F != -1) {
            toVis = true;
            ans += p.F;
            if(p.S) {
                ans++;
                isNastya = true;
            } else ans += 2;
        }
    }

    return {toVis ? ans : -1, isNastya};
}

void solve()
{
    int m, n, a, b, c, d, k, x, y;
    string s1, s2;
    ma.clear();
    vis.clear();
    cin >> n >> k >> x >> y;
    fo(i, k) {
        cin >> a;
        vis.insert(a);
    }
    vis.insert(y);
    fo(i, n-1) {
        cin >> a >> b;
        ma[a].pb(b);
        ma[b].pb(a);
    }
    ma[x].pb(-1);
    auto p = mydfs(x, -1, y);
    cout<<p.F<<ln;

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