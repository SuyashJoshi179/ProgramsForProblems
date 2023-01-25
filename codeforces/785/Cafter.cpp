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

vi ar, ar1(5e4, 0);


void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    cout<<ar1[n]<<ln;
    

}

int main()
{
    fast_cin();
    
    fo(i, 10) ar.pb(i); 
    Fo(i, 1, 10) ar.pb(i*11);
    int i = 0;
    while(ar[i] < 100) {
        Fo(j, 1, 10) {
            ar.pb(j*(ar[i] > 9 ? 1000 : 100) + ar[i]*10 + j);
        }
        i++;
    }
    Fo(j, 1, 10) {
        ar.pb(j*1000 + j);
    }
    while(ar[i] < 1000) {
        if(ar[i] > 99) {
            Fo(j, 1, 10) {
                ar.pb(j*10000 + ar[i]*10 + j);
            }
        }
        i++;
    }
    Fo(j, 1, 10) {
        fo(k, 10) ar.pb(j*10000 + k*100 + j);
    }
    sort(all(ar));
    // for(auto j: ar) cout<<j<<" ";
    // cout<<ln;
    ar1[0] = 1;
    Fo(j, 1, ar.size()) {
        if(ar[j] > 5e4) continue;
        Fo(i, ar[j], 5e4) {
            ar1[i] += ar1[i - ar[j]];
            ar1[i] %= mod;
        }
    }
    // fo(i, 100) cout<<ar1[i]<<" ";
    // cout<<ln;
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}