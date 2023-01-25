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
int ans;

set<pair<int, int>> s;

void myfun(int i, int j, int c0, int c1r) {
    if(s.find({i, j}) != s.end()) return;
    s.insert({i, j});
    cerr<<i<<" "<<j<<ln;
    while(i <= j) {
        if(s1[i] == '0') {
            i++;
            c0--;
        } else if(s1[j] == '0') {
            j--;
            c0--;
        } else {
            ans = min(ans, max(c0, c1r));
            if(i > ) myfun(i+1, j, c0, c1r+1);
            myfun(i, j-1, c0, c1r+1);
            break;
        }
    }
    ans = min(ans, max(c0, c1r));
}

void solve()
{
    int m, n, a, b, c, d;
    
    cin >> s1;
    int i = 0, j = s1.size()-1;
    ans = count(s1.begin(), s1.end(), '0');
    myfun(i, j, ans, 0);
    cout<<ans<<s.size()<<ln;
    

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