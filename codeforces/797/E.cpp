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
    int m, n, a, b, c, d, k;
    string s1, s2;
    cin >> n >> k;
    fo(i, n) cin >> ar[i];
    // vvi v(k);
    // vi took(k, 0);
    // fo(i, n) {
    //     v[ar[i]%k].pb(ar[i]);
    // }
    // fo(i, k) sort(all(v[i]), greater<int>());
    // ll ans = accumulate(all(v[0]), 0ll);
    // took[0] = v.size();
    // if(v[0].size()&1) {
    //     ans -= v[0][v[0].size() -1];
    //     took[0] = v.size()-1;
    // }
    // ans /= k;
    // Fo(i, 0, (k-1)/2) {
    //     a = min(v[i+1].size(), v[k-i].size());
    //     fo(j, a) {
    //         ans += (v[i+1][j] + v[k-i][j])/k;
    //     }
    //     took[i+1] = a;
    //     took[k-i] = a;
    // }
    // if(k&1 == 0) {
    //     b = accumulate(all(v[0]), 0ll);
    // }
    
    // dbg(k);
    sort(ar, ar+n, greater<int>());
    vector<queue<int>> v(k);
    ll ans = 0;
    fo(i, n) {
        a = ar[i]%k;
        b = (a == 0 ? 0 : (k - a));
        if(!v[b].empty()) {
            ans += (0ll + ar[i] + v[b].front())/k;
            // dbg2(ar[i], v[b].front());
            v[b].pop();
        } else {
            v[a].push(ar[i]);
        }
    }
    int l = 0;
    while(l < k) {
        if(v[l].empty()) l++;
        else {
            a = v[l].front();
            v[l].pop();
            b = (l == 0 ? 0 : (k - l));
            while(b < k && v[b].empty()) b++;
            if(b == k) {
                b = l;
                while(b < k && v[b].empty()) b++;
            }
            c = v[b].front();
            v[b].pop();
            ans += (0ll + a + c)/k;
        }
    }
    // vi left;
    // int l = 0;
    // while(l < k) {
    //     if(v[l].empty()) l++;
    //     else {
    //         left.pb(v[l].front());
    //         v[l].pop();
    //     }
    // }
    // sort(all(left), greater<int>());
    // fo(i, left.size()/2) {
    //     ans += (0ll + left[i*2] + left[i*2+1])/k;
    // }
    cout<<ans<<ln;
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