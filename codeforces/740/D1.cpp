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
    ll m, n, a, b, c, d, f = 1;
    string s1, s2;
    cin >> n >> m;
    ar[0] = 1;
    ar[1] = 1;
    ll onetoi = 0, twotoiplus = 1;
    Fo(i, 2, n + 1) {
        ar[i] = onetoi + f;
        c = 0; d = 0, f = 0;
        onetoi += ar[i-1];

        // twotoiplus +=
        Fo(j, 2, i+1) {
            f += ar[i/j];
            f %= m;
            cout<<ar[i/j]<<" ";
        }
        cout<<"two\n";

        int j;
        for(j = 2; j*j <= i; j++) {
            d += ar[i/j];
            d %= m;
            cout<<ar[i/j]<<" ";
        }
        cout<<"one\n"<<i/j-1<<ln;
        for(j = i/j - 1; j > 0; j--) {
            d += (i/j - i/(j+1))*ar[j];
            d %= m;
            cout<<(i/j - i/(j+1))<<","<<ar[j]<<" ";
        }
        cout<<"one\n";
        twotoiplus += d;
        dbg2(f, twotoiplus);
        onetoi %= m;
        twotoiplus %= m;
    }
    cout<<ar[n]<<ln;
    

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