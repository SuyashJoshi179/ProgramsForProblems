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
#define sz(x) ((ll)(x).size())
#define iterate(x) for (auto itr = x.begin(); itr != x.end(); ++itr)

int ar[M];



void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    vvi g(n);
    vi minp(n, 0), an;
    fo(i, n) {
        cin>>m;
        fo(j, m) {
            cin>>a;
            g[i].pb(a);
            minp[i] = max(a + 1 - j, minp[i]);
        }
    }
    vpi mpi;
    fo(i, n) mpi.pb(mp(minp[i], g[i].size()));
    sort(mpi.begin(), mpi.end());
    // iterate(mpi) {
    //     cout<<itr->F<<","<<itr->S<<" ";
    // }
    // cout<<ln;
    c = mpi[0].S; d = mpi[0].F;
    Fo(i, 1, mpi.size()) {
        if(mpi[i].F <= (c + d)) {
            //
        } else {
            d += mpi[i].F - (c + d);
        }
        c += mpi[i].S;
        // an.pb(mpi[i].F - c);
        // c = mpi[i].F + mpi[i].S;
    }
    cout<<d<<ln;
    // fo(i, sz(an)) cout<<an[i]<<" ";
    // cout<<ln;
    // d = 0;
    // fo(i, an.size()) d += an[i] < 0 ? an[i] : 0;
    // cout<<-d + mpi[0].F<<ln;
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