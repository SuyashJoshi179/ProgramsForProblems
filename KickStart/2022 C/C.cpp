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
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n >> m;
    vector<pair<int, pi>> v;
    fo(i, n) {
        cin >> a >> b;
        v.pb({a, {b, i}});
    }
    sort(all(v));
    int l = 0, r = v.size()-1;
    vi ans;
    // int counter = 0;
    while(l <= r) {
        vi droppers;
        while(v[l].F == 0) {
            droppers.pb(v[l].S.S);
            l++;
        }
        while(v[r].F == m) {
            droppers.pb(v[r].S.S);
            r--;
        }
        sort(all(droppers));
        ans.insert(ans.end(), all(droppers));

        Fo(i, l, r) {
            if((v[i+1].F - v[i].F) < 2 && v[i].S.F == 1 && v[i+1].S.F == 0) {
                v[i].S.F = 0;
                v[i+1].S.F = 1;
                if((v[i+1].F - v[i].F) == 1) {
                    v[i].F++;
                    v[i+1].F--;
                };
            }
        }
        Fo(i, l, r+1) {
            if(v[i].S.F == 0) {
                v[i].F--;
            } else {
                v[i].F++;
            }
        }
        // for(auto i: v) cout<<"{"<<i.F<<" "<<i.S.F<<" "<<i.S.S<<"} "; 
        // cout<<ln;
        // Fo(i, l, r+1) {
        //     if(v[i].S.F == 0) {
        //         cout<<-v[i].F<<" ";
        //     } else {
        //         cout<<v[i].F<<" ";
        //     }
        // }
        // cout<<ln;
        // if(++counter > 10) break;
    }
    for(int i: ans) cout<<i+1<<" ";
    cout<<ln;

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