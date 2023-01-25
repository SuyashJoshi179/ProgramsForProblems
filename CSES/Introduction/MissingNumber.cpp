#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n-1);
    for(int &i: v) cin >> i;
    int ans = 0;
    for(int i = 0; i<(n-1); i++) ans ^= v[i] ^ (i+1);
    cout<<(ans ^ n);
    return 0;
}
