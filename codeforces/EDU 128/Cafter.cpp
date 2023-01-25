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
string s1, s2;

bool isPos0(int p, int gc1) {
    int i = -1, j = 0, c0 = 0, c1 = 0;
    // p++;
    for(char ch: s1) {
        if(ch == '0') {c0++; if(c0 == p+1) break;}
        else c1++;
        j++;
    }
    // dbg(p);
    while(j < s1.size()) {
        // dbg2(i, j);
        // dbg(c1);
        if((gc1 - c1) <= p) return true;
        while(s1[++i] == '1') c1--;
        while(s1[++j] == '1') {c1++; if(j == s1.size()) break;}
    }
    // dbg2(i, j);
    if((gc1 - c1) <= p) return true;
    // dbg(false);
    return false;
}

bool isPos1(int p, int gc1) {
    // dbg(p);
    int i = -1, j = 0, c0 = 0, c1 = 0;
    for(char ch: s1) {
        if(ch == '1') {c1++; if((gc1 - c1) == p) break;}
        else c0++;
        j++;
    }
    while(j < s1.size()) {
        // dbg2(i, j);
        // dbg(c0);
        if(c0 <= p) return true;
        while(s1[++i] == '0') c0--;
        while(s1[++j] == '0') {c0++; if(j == s1.size()) break;}
    }
    if(c0 <= p) return true;
    return false;
}

void solve()
{
    int m, n, a, b, c, d;
    cin  >> s1;
    int c0 = count(all(s1), '0'), c1 = s1.size() - c0;
    if(c0 == s1.size() || c0 == 0) {
        cout<<0<<ln;
        return;
    }
    // cout<<ln;
    // Fo(i,0, c0+1) cout<<isPos0(i, c1);
    // cout<<ln;
    // Fo(i, 0, c1 + 1) cout<<isPos1(i, c1);
    // cout<<ln;
    int l = 0, r = c0, t, ans;
    while(l < r) {
        t = (l+r)/2;
        if(isPos0(t, c1)) {
            r = t;
        } else {
            l = t+1;
        }
    }
    ans = l;
    l = 0; r = c1;
    while(l < r) {
        t = (l+r)/2;
        if(isPos1(t, c1)) {
            r = t;
        } else {
            l = t+1;
        }
    }
    cout<<min(l, ans)<<ln;
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