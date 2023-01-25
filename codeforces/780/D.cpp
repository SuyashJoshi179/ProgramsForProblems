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
    cin >> n;
    map<int, pair<int, int> > mp; // nums of 2's => {l, r}
    int i = 0, start = 0, tows = 0;
    bool sign = true;
    fo(i, n) cin >> ar[i];
    while(i != n) {
        a = ar[i];
        if(!a) {
            if(i != start) {
                if(sign) {
                    mp[tows] = {start, i-1};
                } else {
                    int l = start, r = i-1, l2 = 0, r2 = 0;
                    while(ar[l] > 0) {
                        if(ar[l] == 2) l2++;
                        l++;
                    }
                    if(ar[l] == -2) l2++;
                    l++;

                    while(ar[r] > 0) {
                        if(ar[r] == 2) r2++;
                        r--;
                    }
                    if(ar[r] == -2) r2++;
                    r--;

                    if(l2 > r2) {
                        mp[tows - r2] = {start, r};
                    } else {
                        mp[tows - l2] = {l, i-1};
                    }
                }
            }
            tows = 0;
            sign = true;
            start = i+1;
        } else {
            if(abs(a) == 2) tows++;
            if(a < 0) sign = !sign;
        }
        i++;
    }

    // dbg2(i, start);
            if(i != start) {
                if(sign) {
                    mp[tows] = {start, i-1};
                } else {
                    int l = start, r = i-1, l2 = 0, r2 = 0;
                    while(ar[l] > 0) {
                        if(ar[l] == 2) l2++;
                        l++;
                    }
                    if(ar[l] == -2) l2++;
                    l++;

                    while(ar[r] > 0) {
                        if(ar[r] == 2) r2++;
                        r--;
                    }
                    if(ar[r] == -2) r2++;
                    r--;

                    if(l2 > r2) {
                        mp[tows - r2] = {start, r};
                    } else {
                        mp[tows - l2] = {l, i-1};
                    }
                }
            }
    // for(auto i: mp) {
    //     cout<<i.F<<" : "<<i.S.F<<" "<<i.S.S<<ln;
    // }
    if(mp.size() == 0) {
        cout<<n<<" "<<0<<ln;
        return;
    }
    auto itr = --mp.end();
    pair<int, int> p = itr->second;
    // dbg(itr->first);
    
    cout<<(p.first)<<" "<<((n-1) - p.second)<<ln;
    

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