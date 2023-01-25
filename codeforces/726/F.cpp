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

int B[M], A[M], Co[M] = {0};
vpi V;
void solve()
{
    Co[M] = 1;
    int m, n, a, b, c = 1, d = 0;
    cin >> n >> m;
    fo(i, n) cin >> B[i];
    fo(i, n) cin >> A[i];
    fo(i, n) ar[i] = B[i] - A[i];
    fo(i, m) {
        cin>>a>>b;
        V.push_back(make_pair(a, b));
    }
    if(accumulate(ar, ar+n, d) % 2 == 1) {
        cout<<"NO"<<ln;
        cout<<1<<ln;
        return;
    }
    while (c)
    {
        c = 0;
        for(auto x: V) {
            if(Co[x.F] == 0 || Co[x.S] == 0) {
                if(Co[x.F] != 0) Co[x.S] = Co[x.F] == 1 ? 2 : 1;
                else Co[x.F] = Co[x.S] == 1 ? 2 : 1;
                c++;
            } else {
                if(x.F == x.S) {
                    cout<<"YES"<<ln;
                    cout<<2<<ln;
                    return;
                }
            }
        }
    }
    int sum1 = 0, sum2 = 0;
    fo(i, n) {
        if(Co[i] == 1) sum1++;
        else sum2++;
    }
    if((sum1-sum2) % 2  == 0) cout<<"YES"<<ln;
    else cout<<"NO"<<ln;
    cout<<3<<ln;
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