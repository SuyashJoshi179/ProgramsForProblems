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
    int m, n, a, b, c, d, q;
    string s1, s2;
    cin >> n >> m;
    vi edges(n, 0), weaker(n, 0);
    fo(i, m) {
        cin>> a>>b;
        a--; b--;
        edges[a]++;
        edges[b]++;
        a > b ? weaker[a]++ : weaker[b]++;
    }
    d = 0;
    fo(j, n) {
        if(weaker[j] == edges[j]) d++;
    }
    cin>>q;
    fo(i, q) {
        cin>>a;
        if(a == 3) {
            cout<<d<<ln;
        } else if(a == 1) {
            cin>>b>>c;
            c--; b--;
            edges[b]++;
            edges[c]++;
            b > c ? weaker[b]++ : weaker[c]++;
            if(b > c && edges[c] == weaker[c] + 1) {
                d--;
            } else if( b < c && edges[b] == weaker[b] + 1) d--; 
        } else {
            cin>>b>>c;
            c--; b--;
            edges[b]--;
            edges[c]--;
            b > c ? weaker[b]-- : weaker[c]--;
            if(b > c && edges[c] == weaker[c]) {
                d++;
            } else if( b < c && edges[b] == weaker[b]) d++; 
        }
    }

}

int main()
{
    fast_cin();
    int t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}