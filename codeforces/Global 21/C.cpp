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

int ar[M], ar1[M];

bool ispow(ll y, ll x)
{
    if (x == 1)
        return (y == 1);
 
    ll pow = 1;
    while (pow < y)
        pow *= x;
 
    return (pow == y);
}

void solve()
{
    ll m, n, a, b, c, d, k;
    string s1, s2;
    cin >> n >> m;
    fo(i, n) cin >> ar[i];
    cin >> k;
    fo(i, k) cin >> ar1[i];
    a = 0;
    if(accumulate(ar, ar+n, 0ll) != accumulate(ar1, ar1+k, 0ll)) {
        cout<<"NO1"<<ln;
        return;
    }
    a = 0; b = 0;
    ll sa = 0, sb = 0;
    while(a < n && b < k) {
        // dbg2(a, b);
        sa += ar[a++];
        sb += ar1[b++];

        while(sa != sb) {
            dbg2(a, b);
            dbg2(sa, sb);
            if(sa > sb) {
                if(!ispow(sa/sb, m)) {
                    cout<<"NO"<<ln;
                    return;
                }
                sb += ar1[b++];
                if(b == k  && sa != sb) {
                    cout<<"NO"<<ln;
                    return;
                }
            } else {
                if(!ispow(sb/sa, m)) {
                    cout<<"NO"<<ln;
                    return;
                }
                sa += ar[a++];
                if(a == n && sa != sb) {
                    
                    cout<<"NO2"<<ln;
                    return;
                }
            }
        }
        dbg2(a, b);
        dbg2(sa, sb);
        sa = sb = 0;

        // if(ar[a] > ar1[b]) {
        //     c = 0;
        //     while(c < ar[a]) {
        //         if(b == k || ispow((ar[a]/ar1[b]), m) || ar[a]%ar1[b]) {
        //             cout<<"NO2"<<ln;
        //             return;
        //         }
        //         c += ar1[b];
        //         b++;
        //     }
        //     if(c != ar[a]) {
        //         cout<<"NO3"<<ln;
        //         return;
        //     }
        //     a++;
        // } else if(ar[a] < ar1[b]) {
        //     c = 0;
        //     while(c < ar1[b]) {
        //         if(a == n || ispow(ar1[b]/ar[a], m) || ar1[b]%ar[a]) {
        //             cout<<"NO4"<<ln;
        //             return;
        //         }
        //         c += ar[a];
        //         a++;
        //     }
        //     if(c != ar1[b]) {
        //         cout<<"NO5"<<ln;
        //         return;
        //     }
        //     b++;
        // } else {
        //     a++;
        //     b++;
        // }
    }
    // dbg2(a, b);
    if(a == n && b == k && sa == 0 && sb == 0) cout<<"YES"<<ln;
    else cout<<"NO"<<ln;
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