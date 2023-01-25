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
    int m, n, a, b, c, d, k;
    string s1, s2;
    cin >> n >> k >> s1;
    a = 0;
    fo(i, n-1) {
        a += (s1[i]- '0')*10 + (s1[i+1]- '0');
    }
    // cout<<a<<ln;
    // return;
    b = count(all(s1), '1');
    if(k == 0 || b == 0) {
        cout<<a<<ln;
        return;
    }
    int l = 0, r = n-1;
    while(l < s1.size() && s1[l] == '0') l++;
    while(r > -1 && s1[r] == '0') r--;
    r = n-1-r;
    // dbg2(l, r);
    // dbg(a);
    if(b == 1) {
        if(r == 0) {
            cout<<a<<ln;
        } else if(k >= r) {
            cout<<1<<ln;
        } else if(l != 0 && k >= l) {
            cout<<a-1<<ln;
        } else cout<<a<<ln;
        return;
    }
    if(l == 0 || r == 0) {
        if(r != 0 && k >= r) {
            cout<<a-10<<ln;
        } else if(l != 0 && k >= l) {
            cout<<a-1<<ln;
        } else {
            cout<<a<<ln;
        }
        return;
    }
    if(k >= r) {
        if(k >= (l+r)) {
            cout<<a-11<<ln;
        } else {
            cout<<a-10<<ln;
        }
    } else if(k >= l) {
        cout<<a-1<<ln;
    } else {
        cout<<a<<ln;
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