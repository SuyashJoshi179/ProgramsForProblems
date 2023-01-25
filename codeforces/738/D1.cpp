// After knowing how to solve

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

int ar[M];



void solve()
{
    int m, n, a, b, c, d, m1, m2;
    string s1, s2;
    cin >> n >> m1 >> m2;
    union_find f1(n), f2(n);
    fo(i, m1) {
        cin>>a>>b;
        f1.unite(a-1, b-1);
    }
    fo(i, m2) {
        cin>>a>>b;
        f2.unite(a-1, b-1);
    }
    cout<<min(f1.components, f2.components) -1 <<ln;
    fo(i, n) {
        Fo(j, i+1, n) {
            if(f1.find(i) != f1.find(j) && f2.find(i) != f2.find(j)) {
                cout<<i+1<<" "<<j+1<<ln;
                f1.unite(i, j);
                f2.unite(i, j);
            }
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

/*
A good approach for D2 :- 

I have a different approach to problem D2, which is simpler in my opinion.

    First, try to add all edges (1,𝑥) for each 𝑥,

    If they are in the different component of node 1 in both trees, we will add edges from that node.
Now we will consider nodes of two types, the ones that are not in the same component as node 1 in the first tree,
and the ones that are in the same component as node 1 in the second tree.
We will store all nodes of type 1 in a stack 𝑝1, and all nodes of type 2 in a stack 𝑝2, then we will only try to use these nodes and find compatible edges,
for that, we can use the following algorithm -

# If the top of 𝑝1 is in the same component as node 1 in both trees, delete it
# If the top of 𝑝2 is in the same component as node 1 in both trees, delete it
# Otherwise, add an edge between the top of 𝑝1 and the top of 𝑝2.

    Is possible to show that this algorithm will add the same number of edges that the one explained in D1's editorial.
The complexity is almost 𝑂(𝑛+𝑚), since the solution only uses two DSU's, and stacks.

Implementation: https://codeforces.com/contest/1559/submission/126026034
*/