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

ll ar[M];

ll spars[200000][20];

void buildSparse(vector<ll> arr, int size)
{
    for (int i = 0; i < size; i++)
        spars[i][0] = arr[i];
 
    // Build sparse table
    for (int j = 1; j <= 20; j++)
        for (int i = 0; i <= size - (1 << j); i++)
            spars[i][j] = __gcd(spars[i][j - 1], spars[i + (1 << (j - 1))][j - 1]);
}
 
// Returns GCD of arr[L..R]
ll query(int L, int R)
{
    int j = log2(R - L + 1);
    return __gcd(spars[L][j], spars[R - (1 << j) + 1][j]);
}

void solve()
{
    ll m, a, b;
    int c = -1, d, n;
    string s1, s2;
    cin >> n;
    vl array;
    cin >> b;
    fo(i, n-1) {
        cin >> a;
        array.pb(abs(a - b));
        b = a;
    }
    buildSparse(array, array.size());

    fo(i, array.size()) {
        if(query(i, array.size() - 1) > 1) {
            d = array.size() -1 - i;
            c = max(c, d);
            continue;
        }
        int x = i - 1;
        for (int b = array.size() - i - 1; b >= 1; b /= 2) {
            while (query(i, x+b) > 1) x += b;
        }
        c = max(c, x - i);
    }
    cout<<c+2<<ln;
    // fo(i, n-1) {
    //     fo(j, 20) {
    //         cout<<spars[i][j]<<" ";
    //     }
    //     cout<<ln;
    // }
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