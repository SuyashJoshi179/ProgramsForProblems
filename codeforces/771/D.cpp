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
int can[1001][1001];

bool isOfSame(int i, int j) {
    if(i < 0 || j < 0) return(false);
    int c = 0;
    fo(m, 2) fo(n, 2) {
        if(can[i+m][j+n]) {
            if(c) {
                if(can[i+m][j+n] != c) return(false);
            } else c = can[i+m][j+n];
        } 
    };
    return(c);
}

void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n >> m;
    fo(i, n) fo(j, m) {
        cin >> can[i][j];
    };
    queue<pi> q;
    fo(i, n-1) {
        fo(j, m-1) {
            if(isOfSame(i, j)) {
                q.push({i, j});
            }
        }
    }
    vvi ans;
    while(q.size()) {
        int c = 0;
        fo(i, 2) fo(j, 2) {
            if(c == 0) c = can[q.front().first + i][q.front().second + j];
        };
        ans.push_back({q.front().first + 1, q.front().second + 1, c});
        fo(i, 2) fo(j, 2) {
            if(can[q.front().first + i][q.front().second + j]) {
                can[q.front().first + i][q.front().second + j] = 0;
                fo(m, 2) fo(n, 2) {
                    if(isOfSame(q.front().first + i - m, q.front().second + j - n)) {
                        q.push({q.front().first + i - m, q.front().second + j - n});
                    }
                };
            }
        };
        q.pop();
    }
    fo(i, n) fo(j, m) {
        if(can[i][j]) {
            cout<<-1<<ln;
            return;
        }
    };
    cout<<ans.size()<<ln;
    for(auto &i: ans) {
        for(int &j : i) cout<<j<<" ";
        cout<<ln;
    }

}

int main()
{
    fast_cin();
    int t = 1;
    //cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}