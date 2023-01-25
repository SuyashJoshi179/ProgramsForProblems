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
    string s1, s2, s3;
    cin >> n >> m;
    cin >> s1 >> s2;
    a = 0;
    m = n - m;
    fo(i, n) {
        a += (s1[i] == s2[i]);
    }
    if(a >= m) {
        fo(i, n) {
            if(s1[i] == s2[i]) {
                if(m) {
                    cout<<s1[i];
                    m--;
                } else {
                    if(s1[i] == 'a') cout<<'b';
                    else cout<<'a';
                }
            } else {
                char ch = 'a';
                while(s1[i] == ch || s2[i] == ch) ch++;
                cout<<ch;
            }
        }
    } else {
        int c1 = m-a, c2 = m-a;
        fo(i, n) {
            if(s1[i] == s2[i]) {
                s3.push_back(s1[i]);
            } else {
                if(c1) {
                    s3.push_back(s1[i]);
                    c1--;
                } else if(c2) {
                    s3.push_back(s2[i]);
                    c2--;
                } else {
                    char ch = 'a';
                    while(s1[i] == ch || s2[i] == ch) ch++;
                    s3.push_back(ch);
                }
            }
        }
        if(c1 || c2) {
            cout<<-1<<ln;
        } else {
            cout<<s3<<ln;
        }
    }

    

}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}