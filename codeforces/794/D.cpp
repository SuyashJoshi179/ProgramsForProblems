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
    cin >> a >> b >> c >> d >> s1;
    n = s1.size();
    m = count(all(s1), 'A');
    if(a + c + d != m || b + c + d != n-m) {
        cout<<"NO"<<ln;
        return;
    }
    vector<string> ve, vo;
    s2.pb(s1[0]);
    fo(i, n-1) {
        if(s1[i] == s1[i+1]) {
            if(s2.size()&1 && s2.size() != 1) vo.pb(s2);
            else if(s2.size() != 1) ve.pb(s2);
            s2 = s1[i+1];
        } else {
            s2.pb(s1[i+1]);
        }
    }
    if(s2.size()&1 && s2.size() != 1) vo.pb(s2);
    else if(s2.size() != 1) ve.pb(s2);

    sort(all(vo), [] (string &i, string &j) -> bool {return i.size() < j.size();});
    sort(all(ve), [] (string &i, string &j) -> bool {return i.size() < j.size();});
    // dbg2(c, d);
    // for(auto i: ve) cout<<i<<" ";
    // cout<<ln;
    // for(auto i: vo) cout<<i<<" ";
    // cout<<ln;
    for(auto s: ve) {
        n = s.size();
        if(s[0] == 'A') {
            m = min(c, n/2);
            c -= m;
            if(c == 0) d -= min(d, max(n - m*2 - 2, 0)/2);
        } else {
            m = min(d, n/2);
            d -= m;
            if(d == 0) c -= min(c, max(n - m*2 - 2, 0)/2);
        }
    }
    for(auto s: vo) {
        n = s.size();
        m = min(c, n/2);
        c -= m;
        if(c == 0) d -= min(d, n/2 - m);
    }
    // dbg2(c, d);
    if(c || d) {
        cout<<"NO"<<ln;
    } else {
        cout<<"YES"<<ln;
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