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
int ar1[M];



void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    fo(i, n) cin >> ar[i];
    fo(i, n) cin >> ar1[i];

    vector<bool> v(n, true);
    vector<bool> canfail(n, false);
    
    fo(i, n) {
        fo(j, n) {
            //can i fail from j?
            if((ar[i] < ar[j]) || (ar1[i] < ar1[j])) {
                canfail[i] = true;
                break;
            };
        }
    }
    fo(i, n) {
        if(!canfail[i]) {
            fo(j, n) {
                cout<<(canfail[j] ? "0" : "1");
            }
            cout<<ln;
            return;
        }
    }
    fo(j, n) {
        cout<<(canfail[j] ? "1" : "0");
    }
    cout<<ln;
    return;
    // cout<<"Canfail: ";
    // fo(i, n) {
    //     cout<<(canfail[i] ? "1" : "0");
    // }
    // cout<<ln;
    
    // fo(i, n-1) {
    //     Fo(j, i+1, n) {
    //         //can i win over j?
            
    //         if(!canfail[j] && (ar[i] < ar[j]) && (ar1[i] < ar1[j])) {
    //             v[i] = false;
    //             //cout<<i<<" Failed from "<< j<<ln;
    //         }
    //         //can j win over i?
    //         if(!canfail[i] &&(ar[i] > ar[j]) && (ar1[i] > ar1[j])) {
    //             v[j] = false;
    //             //cout<<j<<" Failed from "<< i<<ln;
    //         }

    //     }
    // }
    // fo(i, n) {
    //     cout<<(v[i] ? "1" : "0");
    // }
    // cout<<ln;
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