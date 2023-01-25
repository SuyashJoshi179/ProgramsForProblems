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

int ar[101][101];



void solve()
{
    ll m, n, a, b, c, d, md = 998244353;
    string s1, s2;
    cin >> n;
    string s(n, '0');
    fo(i, n) {
        Fo(j, i, n) {
            cin >> ar[i][j];
            if(i != j && ar[i][j] == 1) {
                Fo(k, i, j+1) s[k] = '1';
            }
        } 
    }
    cout<<s<<ln;
    vi v;
    char prev = '0';
    fo(i, n) {
        if(s[i] == '1' && prev == '1');
        else v.pb(i);
        prev = s[i];
    }
    
    // b = count(s.begin(), s.end(), '1');
    // a = !!b + 1;
    // fo(i, n-b) {
    //     a *= 2;
    //     a %= md;
    // }
    
    for(int i:v) cout<<i<<" ";
    cout<<ln;

    // fo(i, n-1) {
    //     Fo(j, i+1, n) {
    //         if(ar[i][j] == 2) {
    //             if(!count(s.begin() + i, s.begin()+ j+1, '0')) {
    //                 cout<<0<<ln;
    //                 return;
    //             }
                
    //         }
    //     }
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