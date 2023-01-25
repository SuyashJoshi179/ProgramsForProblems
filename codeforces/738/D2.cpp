// For approach, see at end of D1.cpp.

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

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;
 
    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }
 
    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }
 
    int get_size(int x) {
        return -data[find(x)];
    }
 
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
 
        if (x == y)
            return false;
 
        if (-data[x] < -data[y])
            swap(x, y);
 
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

void solve()
{
    int m, n, a, b, c, d, m1, m2;
    string s1, s2;
    cin >> n >> m1 >> m2;
    union_find f1(n), f2(n);
    vpi ans;
    vi v1, v2;
    fo(i, m1) {
        cin>>a>>b;
        f1.unite(a-1, b-1);
    }
    fo(i, m2) {
        cin>>a>>b;
        f2.unite(a-1, b-1);
    }
    Fo(i, 1, n) {
        if(f1.find(i) != f1.find(0) && f2.find(i) != f2.find(0)) {
            ans.pb(mp(0, i));
            f1.unite(0, i);
            f2.unite(0, i);
        }
        if(f1.find(i) != f1.find(0)) v1.pb(i);
        if(f2.find(i) != f2.find(0)) v2.pb(i);
    }

    while (!v1.empty() && !v2.empty())
    {
        if(f1.find(v1.back()) == f1.find(v2.back())) {
            v1.pop_back();
            continue;
        }
        if(f2.find(v1.back()) == f2.find(v2.back())) {
            v2.pop_back();
            continue;
        }
        ans.pb(mp(v1.back(), v2.back()));
        f1.unite(v1.back(), v2.back());
        f2.unite(v1.back(), v2.back());
    }
    
    cout<<ans.size()<<ln;
    for(auto i: ans) cout<<i.F+1<<" "<<i.S+1<<ln;
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