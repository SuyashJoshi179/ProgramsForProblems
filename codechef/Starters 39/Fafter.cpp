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
vvi tree, paths;
void pathFinder(int root, int parent) {
    for(int i: tree[root]) {
        if(i != parent) {
            for(int j: paths[root]) paths[i].pb(j);
            paths[i].pb(i);
            pathFinder(i, root);
        }
    }
}

void solve()
{
    int m, n, a, b, c, d, q;
    string s1, s2;
    cin >> n >> s1;
    tree.clear();
    paths.clear();
    tree.resize(n);
    paths.resize(n);
    fo(i, n-1) {
        cin >> a >> b;
        tree[a-1].pb(b-1);
        tree[b-1].pb(a-1);
    }
    paths[0].pb(0);
    pathFinder(0, -1);

    cin >> q;
    fo(i, q) {
        cin >> a >> b;
        if(a == b) {
            cout<<"NO"<<ln;
            continue;
        }
        a--; b--;
        c = 0;
        d = min(paths[a].size(), paths[b].size());
        while(c < d && paths[a][c] == paths[b][c]) c++;
        if(c == d) {
            cout<<"NO"<<ln;
            continue;
        }
        unordered_set<char> st;
        Fo(j, c, paths[a].size()) st.insert(s1[paths[a][j]]);
        bool f = true;
        Fo(j, c, paths[b].size()) {
            if(st.find(s1[paths[b][j]]) != st.end()) {
                cout<<"YES"<<ln;
                f = false;
                break;
            }
        }
        if(f) cout<<"NO"<<ln;
    }

    

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