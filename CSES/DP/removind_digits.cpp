#include <bits/stdc++.h>
using namespace std;
int main() {
    int c, m = 2e9;
    cin >> c;
    vector<int> ar(c+1, m);
    ar[0] = 0;
    int j;
    for(int i = 0; i<=c; i++) {
        j = i;
        while(j) {
            ar[i] = min(ar[i], ((i - j%10 >=0) ? ar[i - j%10] : m) + 1);
            j /= 10;
        }
    }
    cout<<ar[c];
    return 0;
}
