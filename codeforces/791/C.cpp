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

int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
    // Add 'val' to current node of BI Tree
    BITree[index] += val;
 
    // Update index to that of parent in update View
    index += index & (-index);
    }
}
 
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //     cout << BITree[i] << " ";
 
    return BITree;
}


int rows[M];
int cols[M];

int *t1, *t2;

int m, n, a, b, c, d;
string s1, s2;


void solve()
{
    cin >> m;
    if(m == 1) {
        cin >> a >> b;
        if(rows[a-1] == 0) updateBIT(t1, n, a-1, 1);
        rows[a-1]++;
        if(cols[b-1] == 0) updateBIT(t2, n, b-1, 1);
        cols[b-1]++;
    } else if(m == 2) {
        cin >> a >> b;
        rows[a-1]--;
        if(rows[a-1] == 0) updateBIT(t1, n, a-1, -1);
        cols[b-1]--;
        if(cols[b-1] == 0) updateBIT(t2, n, b-1, -1);
    } else {
        cin >> a >> c >> b >> d;
        bool row = true, col = true;
        // Fo(i, a-1, b) {
        //     if(rows[i] == 0) row = false;
        //     // dbg2(i, rows[i]);
        // }
        row = ((b-a+1) == (getSum(t1, b-1) - getSum(t1, a-2) ));
        if(row) {
            cout<<"Yes"<<ln;
            return;
        }
        // Fo(i, c-1, d) {
        //     if(cols[i] == 0) col = false;
        //     // dbg2(i, rows[i]);
        // }
        col = ((d-c+1) == (getSum(t2, d-1) - getSum(t2, c-2)));
        if(row || col) {
            cout<<"Yes"<<ln;
        } else cout<<"No"<<ln;
    }
    

}

int main()
{
    fast_cin();
    int t = 1;
    cin >> n;
    cin >> t;
    fo(i, n) {
        rows[i] = 0;
        cols[i] = 0;
    }

    t1 = constructBITree(rows, n);
    t2 = constructBITree(cols, n);

    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}