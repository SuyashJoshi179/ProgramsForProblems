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

ll ar[1000]; // ki
ll ar1[1000]; // hi
ll ar2[1000];

void solve()
{
    ll m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar[i];
    fo(i, n) cin >> ar1[i];
    vector<pair<long long, long long> > ans;
    fo(i, n) {
        a = ar[i] - ar1[i], b = ar[i];
        while(ans.size() && ans.back().F >= a) {
            ans.pop_back();
        }
        c = a;
        if(ans.size() && ans.back().F < a && ((ans.back().F + ans.back().S) > a)) c = ans.back().F, ans.pop_back();
        ans.push_back(mp(c, ar1[i] + a - c));
        //cout<<ans.back().F<<":"<<ans.back().S<<ln;
    }
    ll answer = 0;
    for(auto i: ans) {
        // cout<<i.F<<":"<<i.S<<" ";
        answer += (1ll * i.S * (i.S + 1)) / 2;
    }
    cout<<answer<<ln;
    //cout<<accumulate(ans.begin(), ans.end(), 0)<<ln;

}

int main()
{
    fast_cin();
    int t = 1;
    // prei(ni, 2);
    // prei(ni, 7);
    // for(auto i: ni) {
    //     cout<<i<<" ";
    // }
    // cout<<ln;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}