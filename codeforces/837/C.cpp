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

vector<int> longest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum)
{
    maximum = max(maximum, 1);
    longest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p])
        {
            longest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i])
                {
                    prime[i] = false;
                    longest_factor[i] = p;
                }
        }
}

void solve()
{
    int m, n, a, b, c, d;
    string s1, s2;
    cin >> n;
    a = 0;
    fo(i, n) {
        cin >> b;
        if(b > 1) ar[a++] = b; 
    };
    n = a;
    set<int> s(ar, ar+n);
    if(s.size() != n) {
        cout<<"YES"<<ln;
        return;
    }
    for(int p: primes) {
        bool f = false;
        fo(i, n) {
            if(ar[i] >= p && (ar[i]%p) == 0) {
                if(f) {
                    cout<<"YES"<<ln;
                    return;
                } else f = true;
            }
        }
    }
    cout<<"NO"<<ln;

}

int main()
{
    fast_cin();
    sieve(M);
    // for(int p: primes) cout<<p<<ln;
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}