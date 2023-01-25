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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
 
#define ordered_set_greater tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

ll ar[M];



void solve()
{
    ll m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    ordered_set os;
    fo(i, n) cin >> ar[i];
    vector<ll> v(n, 0);
    // Fo(i, n-1, -1) {
    //     a = os.order_of_key(ar[i]);
    //     v[i] = a;
    //     os.insert(ar[i]);
    // }
    // ll sm = 0;
    // for(auto &i: v) {
    //     sm += i;
    //     i = sm;
    // }
    // // for(auto i: v) cout<<i<<" ";
    // // cout<<ln;
    ll ans = 0;
    fo(i, n-1) {
        a = 0;
        Fo(j, n-1, i) {
            b = v[j];
            // Fo(k, j+1, n) {
            //     if(ar[i] > ar[k]) a++;
            // }
            // Fo(k, i-1, -1) {
            //     if(ar[j] > ar[k]) b++;
            // }
            ans += (a*b);
            if(ar[j] < ar[i]) a++;
            if(ar[j] > ar[i]) v[j]++;
        }
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