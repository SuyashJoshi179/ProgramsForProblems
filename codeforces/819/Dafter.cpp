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
typedef vector<vector<pi>> vvpi;
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
    vvpi graph(n);
    vpi edges;
    fo(i, m) {
        cin >> a >> b;
        a--; b--;
        edges.pb({a, b});
        graph[a].pb({b, edges.size()-1});
        graph[b].pb({a, edges.size()-1});
    }
    vector<bool> spanning(m, false);
    queue<int> q;
    q.push(0);
    vector<bool> vis(n, false);
    vis[0] = true;
    while(!q.empty()) {
        a = q.front();
        q.pop();
        for(auto i: graph[a]) {
            if(vis[i.first] == false) {
                vis[i.first] = true;
                spanning[i.second] = true;
                q.push(i.first);
            }
        }
    }
    
    // Check for cycle in non-spanning edges.
    if(m-n > 1) {
        bool cycle = false;
        vi leftovers;
        fo(i, m) {
            if(spanning[i] == false) leftovers.pb(i);
        }
        set<int> s;
        for(auto p: leftovers) {
            if(s.find(edges[p].second) != s.end() && s.find(edges[p].first) != s.end()) {
                cycle = true;
            } else {
                s.insert(edges[p].first);
                s.insert(edges[p].second);
            }
        }
        if(cycle) {
            int p = leftovers[0];
            for(auto i: graph[edges[p].first]) {
                if(spanning[i.second]) {
                    spanning[i.second] = 0;
                    spanning[p] = 1;
                    break;
                }
            }
        }
    }
    for(bool i: spanning) cout<<i;
    cout<<ln;
    // cout<<n-m+n<<ln;

    

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