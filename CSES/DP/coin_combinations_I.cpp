#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, c, m = 1e9 + 7;
    cin>>n>>c;
    int arr[n];
    vector<int> ar(c+1, 0);
    for(int i = 0; i< n; i++) cin>>arr[i];
    ar[0] = 1;
    for(int i = 1; i<=c; i++) {
        for(int j = 0; j < n; j++) {
            ar[i] += (i - arr[j] >= 0 ? ar[i - arr[j]] : 0);
            ar[i] %= m;
        }
    }
    cout<<ar[c]<<"\n";
    return 0;
}
