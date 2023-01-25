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
int mx;
int toinc(vi included, int i, int n, vpi ab, bool li, int cap) {
    i++;
    int n1 = included.size();
    if(i == n+1) {
        mx = max(mx, n1);
        return(n1);
    }
    if(li) {
        if((n1 + n - i + 1) <= mx) {
            return(n1 + n - i + 1);
        }
    }

    bool flag = true;
    
    if(cap == n1) {
        flag = false;
    }
    
    // fo(j, n1) {
    //     if(ab[included[j]-1].S == (n1 - j - 1)) {
    //         flag = false;
    //         break;
    //     }
    // }
    if(ab[i-1].F < n1) {
        flag = false;
    }
    if(flag) {
        int a1 = toinc(included, i, n, ab, true, cap);
        vi inc2 = included;
        inc2.pb(i);
        int a2 = toinc(inc2, i, n, ab, false, min(cap, (n1+1+ab[i-1].S)));
        return(max(a1, a2));
    } else {
        return(toinc(included, i, n, ab, true, cap));
    }

}

void solve()
{
    ll m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    vpi ab;
    fo(i, n) {
        cin >> a >> b;
        ab.pb({b, a});
    }
    vi inc;
    mx = 0;
    cout<<toinc(inc, 0, n, ab, false, INF)<<ln;

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