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
const int M = 500002;
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

int ar[1000002], ar1[M], lps[M];



void solve()
{
    int m, n, a, b, c, d, k;
    string s1, s2;
    cin >> n >> k;
    fo(i, n) cin >> ar[i];
    fo(i, n) cin >> ar1[i];
    fo(i, n) ar[i+n] = ar[i];
    
    vi A;
    
    lps[0] = 0;
    int j = 0, i;
    for(i = 1; i < n; i++) {
        if(ar1[i] == ar1[j]) lps[i] = ++j;
        else {
            while(ar1[i] != ar1[j]) {
                if(j == 0) break;
                else j = lps[j-1];
            }
            lps[i] = j;
        }
    }
    
    // cout<<ln;
    // fo(i, n) cout<<lps[i]<<" ";
    // cout<<ln;

    i = 0; j = 0;
    while(i < (2*n-1)) {
        if(ar[i] == ar1[j]) i++, j++;
        if(j == n) {
            A.pb(i-n);
            j = lps[j-1];
        }
        else if(i < (2*n) && ar[i] != ar1[j]) {
            if(j == 0) {
                i++;
            } else {
                j = lps[j-1];
            }
        }
    }
    // for(auto i: A) cout<<i<<" ";
    // cout<<ln;
    // return;

    if(A.size() == 0) {
        cout<<"NO"<<ln;
        return;
    }

    if(k == 0) {
        if(A[0] == 0) cout<<"YES"<<ln;
        else cout<<"NO"<<ln;
        return;
    }
    
    if(n == 2) {
        if(k%2 == A[0] || A.size() > 1) cout<<"YES"<<ln;
        else cout<<"NO"<<ln;
        return;                 
    } 

    if(A[0] == 0 && k == 1 && (A.size() == 1 || A[1] != 1)) {
        cout<<"NO"<<ln;
        return;
    }

    cout<<"YES"<<ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout<<"Case #"<<it<<": ";
        solve();
    }
    return 0;
}