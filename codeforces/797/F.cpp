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



void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n >> s1;
    fo(i, n) cin >> ar[i];
    vector<bool> vis(n, false);
    vector<string> v;
    fo(i, n) {
        if(vis[i] == false) {
            a = ar[i]-1;
            s2.clear();
            s2.pb(s1[i]);
            vis[i] = true;
            while(a != i) {
                s2.pb(s1[a]);
                vis[a] = true;
                a = ar[a]-1;
            }
            v.pb(s2);
        }
    }
    // for(auto i: v) cout<<i<<" ";
    // cout<<ln;

    vector<ll> nums;
    for(auto s: v) {
        a = s.size();
        if(a == 1) continue;
        s2 = s;
        Fo(i, 1, s.size()) {
            rotate(s2.begin(), s2.begin()+1, s2.end());
            if(s2 == s) {
                a = i;
                break;
            }
        }
        nums.pb(a);
    }
    if(nums.size() == 0) {
        cout<<1<<ln;
        return;
    }
    ll ans = nums[0];
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < nums.size(); i++)
        ans = (((nums[i] * ans)) /
                (__gcd(nums[i], ans)));
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