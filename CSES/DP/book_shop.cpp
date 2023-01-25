#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> pages(n), prices(n), dp(x+1, 0);
    for(auto &i: prices) cin >> i;
    for(auto &i: pages) cin >> i;
    
    for(int j = 0; j < n; j++) {
        for(int i = x; i > -1; i--) {
            if((i - prices[j]) >= 0) dp[i] = max(dp[i], (dp[i - prices[j]] + pages[j]));
        }
    }
    cout<<*max_element(dp.begin(), dp.end());

    return 0;
}
