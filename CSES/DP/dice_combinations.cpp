#include <bits/stdc++.h>
using namespace std;
int main() {
    int c;
    cin >> c;
    int arr[c+1] = {0}, m = 1e9 + 7;
    arr[0] = 1;
    for(int i = 0; i<=c; i++) {
        for(int j = 1; j <= 6; j++) {
            arr[i] += (i - j >= 0) ? arr[i-j] : 0; 
            arr[i] %= m;
        }
    }
    cout<<arr[c]<<"\n";
    return 0;
}
