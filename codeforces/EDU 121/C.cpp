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

ll ar[1000]; // ki
ll ar1[1000]; // hi
ll ar2[1000];
void precalc(vector<long long> &ni) {
    ll a = 0;
    fo(i, 1e9) {
       a+=i;
       ni.pb(a);
    }
}

ll prei(vector<long long> &ni, int n) {
    if(n < ni.size()) {
        return(ni[n]);
    } else {
        ll a = ni[ni.size() - 1];
        Fo(i, ni.size(), n+1) {
            a+=i;
            ni.pb(a);
        }
        return(ni[n]);
    }
}

void solve(vector<long long> &ni)
{
    ll m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar[i];
    fo(i, n) cin >> ar1[i];
    vl ans(ar[n-1], 0);
    Fo(i, n-1, -1) {
        if(ans[ar[i]] > ar1[i]) {
            continue;
        } else if(ans[ar[i]] == 0) {
            a = ar1[i]; b = 1;
            dbg2(a, ar[i]);
            while(a) {
                ans[ar[i] - b] = a;
                b++;
                a--;
            }
        } else {
            a = ar1[i]; b = 1;
            dbg2(a, ar[i]);
            while(a) {
                ans[ar[i] - b] = a;
                b++;
                a--;
            }
            b = 0;
            while(ans[ar[i] + b] > 1) {
                ans[ar[i] + b] = a + b;
                b++;
            }
        }
        // else {
        //     while()
        //     ans.pb(prei(ni, ar[i] - prevk + prevh) - prei(ni, prevh));
        //     prevh = ar[i] - prevk + prevh;
        //     prevk = ar[i];
        // }
    }
    for(auto i: ans) {
        cout<<i<<" ";
    }
    cout<<ln;
    //cout<<accumulate(ans.begin(), ans.end(), 0)<<ln;

}

int main()
{
    fast_cin();
    int t = 1;
    vector<long long> ni;
    ni.pb(0);
    // prei(ni, 2);
    // prei(ni, 7);
    // for(auto i: ni) {
    //     cout<<i<<" ";
    // }
    // cout<<ln;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve(ni);
    }
    return 0;
}