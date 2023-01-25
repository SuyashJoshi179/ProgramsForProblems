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

string check(string a, string s, int ai, int si) {
    if(ai < 0 && si == -1 ) return("");
    if( si < 0 ) return("-1");
    int s1 = s[si] - '0', s2 = ((si - 1) >= 0) ? stoi(s.substr(si-1, 2), 0) : -1, a1 = (ai < 0) ? 0 : (a[ai] - '0');
    string ans1 = "-1", ans2 = "-1";
    if((s1 - a1) < 10 and (s1 - a1) > -1) {
        ans1 = check(a, s, ai-1, si-1);
    }
    if(s2 > 9 and (s2 - a1) < 10 and (s2 - a1) > -1) {
        ans2 = check(a, s, ai-1, si-2);
    }
    if(ans1 != "-1") {
        return(ans1 + (char)(s1 - a1 + '0'));
    } else if(ans2 != "-1") {
        return(ans2 + (char)(s2 - a1 + '0'));
    } else {
        return("-1");
    }
}

void solve()
{
    ll m, n, b, c, d;
    string a, s, ans;
    cin >> a >> s;
    ans = check(a, s, a.length() - 1, s.length() - 1);
    int i = 0;
    while(ans[i] == '0') i++;
    cout<<ans.substr(i)<<ln;
    

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