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
string s1, s2;

int cost(int i, int c) {
    c += '0';
    i *= 2;
    // dbg2(s1[i], s1[i+1]);
    // dbg(c);
    return((s1[i] != c) + (s1[i+1] != c));
}

void solve()
{
    int m, n, a = 0, b, c, d;
    cin >> n >> s1;
    pair<pi, pi> curr = {{0, 0}, {0, 0}}, prev = {{0, 0}, {0, 0}};
    fo(i, n/2) {
        a += !!(s1[i*2]^s1[i*2+1]);
        curr.F = min(mp(prev.F.F + cost(i, 0), prev.F.S), mp(prev.S.F + cost(i, 0), prev.S.S + 1));
        curr.S = min(mp(prev.F.F + cost(i, 1), prev.F.S + 1), mp(prev.S.F + cost(i, 1), prev.S.S));
        // cout<<curr.F<<" : "<<curr.S<<ln;
        prev = curr;
    }
    pi ans = min(curr.F, curr.S);
    cout<<ans.F<<" "<<ans.S<<ln;
    

    

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