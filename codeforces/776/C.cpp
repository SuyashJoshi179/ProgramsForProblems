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

bool compare(vi &a, vi &b) {
    return(a[0] < b [0]);
}

void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n >> m;
    vvi gr, gr1, gr2;
    fo(i, m) {
        cin >> a >> b;
        gr.pb({b, a, i});
    }
    sort(all(gr), compare);
    fo(i, 2*n) {
        gr1.pb({gr[i][1], gr[i][0], gr[i][2]});
    }
    sort(all(gr1), compare);
    int ans = 0;
    fo(i, n) {
        gr2.push_back({gr1[i][2], gr1[2*n-i-1][2]});
        ans += gr1[i][1] + gr1[2*n-i-1][1];
    }
    cout<<ans<<ln;
    fo(i, n) {
        cout<<gr2[i][0]+1<<" "<<gr2[i][1] +1<<ln;
    }


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