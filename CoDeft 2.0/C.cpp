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

ll ar[500000];



void solve()
{
    ll m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar[i];
    ll lsum = 2e9, gsum = 2e9, ls = 0;
    pi gs = {0, 0};
    fo(i, n) {
        if(lsum > 0) {
            lsum = ar[i];
            ls = i;
        } else {
            lsum += ar[i];
        }
        if(gsum > lsum) {
            gsum = lsum;
            gs = {ls, i};
        }
    }
    cout<<gs.first<<" "<<gs.second<<ln;
    if(gs.second - gs.first > 4) {
        cout<<accumulate(ar, ar+gs.first, 0ll) - accumulate(ar+gs.first +1, ar+gs.second, 0ll) + max_element(ar+gs.first +1, ar+gs.second) + accumulate(ar+gs.second + 1, ar+n, 0ll)<<ln; 
        return;
    } else {
        
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