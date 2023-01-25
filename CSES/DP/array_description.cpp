#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a;
    cin >> n >> m;
    vector<long long> dp(m, 0); 

    cin >> a;
    if(a == 0) {
        for(auto &i: dp) i = 1; 
    } else {
        dp[a-1] = 1;
    }

    for(int i = 1; i<n; i++) {
        cin >> a;
        if(a == 0) {
            vector<long long> ndp(m); 
            for(int j = 0; j < m; j++) {
                ndp[j] = (j ? dp[j-1] : 0) + dp[j] + (j != (m-1) ? dp[j+1] : 0);
                ndp[j] %= 1000000007;
            }
            dp = ndp;
        } else {
            int j = a-1;
            dp[j] = (j ? dp[j-1] : 0) + dp[j] + (j != (m-1) ? dp[j+1] : 0);
            dp[j] %= 1000000007;
            for(j = 0; j < m; j++) {
                if((j+1) != a) dp[j] = 0;
            }
        }
        // for(auto i: dp) cout<<i<<" ";
        // cout<<endl;
    }
    long long ans = 0;
    for(auto i: dp) {
        ans += i;
        ans %= 1000000007;
    }
    cout<<ans;
    return 0;
}
