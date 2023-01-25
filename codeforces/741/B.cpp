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

 // only 9 is left
multiset<int> pri({1, 4, 6, 8, 9}), num; // 2, 3, 5, 7

void solve()
{
    int m, n, a, b, d = 100;
    char c;
    bool f = false, s = false;
    string s1, s3;
    cin >> n >> s1;
    fo(i, n) {
        string s2;
        a = s1[i] - '0';
        if(pri.find(a) != pri.end()) {
            cout<<1<<ln<<a<<ln;
            return;
        }
        if(a == 2) {
            if(n == 1) {
                cout<<-1<<ln;
            } else {
                if(d > 2 && i) {
                    d = 2;
                    s2.pb(s1[i-1]);
                    s2.pb('2');
                    s3 = s2;
                }
            }
        }
        if(a == 5) {
            if(n == 1) {
                cout<<-1<<ln;
            } else {
                if(d > 2 && i) {
                    d = 2;
                    s2.pb(s1[i-1]);
                    s2.pb('5');
                    s3 = s2;
                }
            }
        }
        if(a == 7) {
            if(i && (s1[0] == '2' || s1[0] == '5')) {
                if(d > 2) {
                    d = 2;
                    s2.pb(s1[0]);
                    s2.pb('7');
                    s3 = s2;
                }
            }
            fo(j, n) {
                if(s1[j] == '7' && j != i) {
                    if(d > 2) {
                        d = 2;
                        s3 = "77";
                    }
                }
            }
        }
        if(a == 3) {
            fo(j, n) {
                if(s1[j] == '3' && j != i) {
                    if(d > 2) {
                        d = 2;
                        s3 ="33";
                    }
                }
            }

        }
    }
    if(d == 100) {
        cout<<"Heck "<<s1<<ln<<ln;
        return;
    }
    cout<<d<<ln<<s3<<ln;

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