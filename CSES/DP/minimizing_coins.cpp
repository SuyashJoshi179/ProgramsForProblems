#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, c, m = 2e9;
    cin>>n>>c;
    int arr[n];
    vector<int> ar(c+1, m);
    for(int i = 0; i< n; i++) cin>>arr[i];
    ar[0] = 0;
    for(int i = 1; i<=c; i++) {
        for(int j = 0; j < n; j++) {
            ar[i] = min(ar[i], (i - arr[j] >= 0 ? ar[i - arr[j]] : m) + 1);
        }
    }
    cout<<(ar[c] >= 2e9 ? -1 : ar[c])<<"\n";
    return 0;
}
