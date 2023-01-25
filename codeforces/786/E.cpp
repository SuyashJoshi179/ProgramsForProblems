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

int myceil(int a, int b)
{
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}

ll myceill(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}

void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar[i];
    ar[n] = 2e9;
    int fl = n, sl = n;
    fo(i, n) {
        if(ar[i] <= ar[fl]) {
            sl = fl;
            fl = i;
        } else if(ar[i] < ar[sl]) {
            sl = i;
        }
    }
    int ans = 2e9;
    if(abs(sl - fl) > 1) ans = myceil(ar[fl], 2) + myceil(ar[sl], 2);
    
    fo(i, n-1) {
        a = ar[i]; b = ar[i+1];
        // c = 0;
        // while(a > 0 || b > 0) {
        //     if(a > b) {
        //         a -= 2;
        //         b--;
        //     } else {
        //         b -= 2;
        //         a--;
        //     }
        //     c++;
        // }
        // ans = min(ans, c);
        int d = myceill(a+b, 3);
        ans = min(ans, d);
    }
    fo(i, n-2) {
        ans = min(ans, max(ar[i], ar[i+2]));
    }
    cout<<ans<<ln;
}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}