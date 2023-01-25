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
    int m, n, a, b, c, d, m1, m2;
    string s1, s2;
    cin >> n >> m1 >> m2;
    vpi e1, e2;
    fo(i, m1) {
        cin >> a >> b;
        e1.pb(mp(a-1, b-1));
    }
    fo(i, m2) {
        cin >> a >> b;
        e2.pb(mp(a-1, b-1));
    }
    vi v1(n), v2(n);
    fo(i, n) {
        v1[i] = i;
        v2[i] = i;
    }
    bool f = true;
    while(f) {
        f = false;
        for(auto i : e1) {
            if(v1[i.F] != v1[i.S]) {
                v1[i.F] = v1[i.S] = min(v1[i.F], v1[i.S]);
                f = true;
            } 
        }
    }
    
    // for v2
    f = true;
    while(f) {
        f = false;
        for(auto i : e2) {
            if(v2[i.F] != v2[i.S]) {
                v2[i.F] = v2[i.S] = min(v2[i.F], v2[i.S]);
                f = true;
            } 
        }
    }
    unordered_set<int> S1(v1.begin(), v1.end()), S2(v2.begin(), v2.end());
    for(auto i = S1.begin(); i != S1.end(); i++) cout<<*i<<" ";
    cout<<ln;
    for(auto i = S2.begin(); i != S2.end(); i++) cout<<*i<<" ";
    cout<<ln;
    
    vpi answers;
    fo(i, n) {
        Fo(j, i, n) {
            if(v1[i] != v1[j] && v2[i] != v2[j]) {
                answers.pb(mp(i, j));
            }
        }
    }
    unordered_map<int, int> u1, u2;
    unordered_set<int> se;
    fo(ii, answers.size()) {
        pi i = answers[ii];
        auto i1 = u1.find(v1[i.F]);
        auto i2 = u1.find(v1[i.S]);
        if(i1 == u1.end() && i2 == u1.end()) {
            se.insert(ii);
            u1[v1[i.F]] = u1[v1[i.S]] = min(v1[i.F], v1[i.S]);
        } else if(i1 == u1.end()) {
            se.insert(ii);
            u1[v1[i.F]] = u1[v1[i.S]];
        } else if(i2 == u1.end()) {
            se.insert(ii);
            u1[v1[i.S]] = u1[v1[i.F]];
        } else if(u1[v1[i.S]] != u1[v1[i.F]])
            se.insert(ii);
    }
    for(auto i : se) cout<<i<<">";
    cout<<endl;
    fo(ii, answers.size()) {
        pi i = answers[ii];
        auto i1 = u2.find(v2[i.F]);
        auto i2 = u2.find(v2[i.S]);
        if(i1 == u2.end() && i2 == u2.end()) {
            if(se.find(ii) != se.end()) {
                cout<<ii<<" "<<i.F<<" "<<i.S<<ln;
                u2[v2[i.F]] = u2[v2[i.S]] = min(v2[i.F], v2[i.S]);
            }
        } else if(i1 == u2.end()) {
            if(se.find(ii) != se.end()) {
                cout<<ii<<" "<<i.F<<" "<<i.S<<ln;
                u2[v2[i.F]] = u2[v2[i.S]];
            }
        } else if(i2 == u2.end()) {
            if(se.find(ii) != se.end()) {
                cout<<ii<<" "<<i.F<<" "<<i.S<<ln;
                u2[v2[i.S]] = u2[v2[i.F]];
            }
        } else if(u2[v2[i.S]] != u2[v2[i.F]])
            if(se.find(ii) != se.end()) {
                cout<<ii<<" "<<i.F<<" "<<i.S<<ln;
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