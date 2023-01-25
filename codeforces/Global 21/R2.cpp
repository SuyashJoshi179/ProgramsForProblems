#include <bits/stdc++.h>

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

long long ar[(int)(1e6 + 100)];

int main() {
    fast_cin();
    long long n, pm, cmx, pi, ci, ans = 0;
    map<int, int> ma;
    
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> ar[i];
    }
    cout<<ans<<"\n";
    return 0;
}
