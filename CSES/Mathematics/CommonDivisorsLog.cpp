#include <bits/stdc++.h>
using namespace std;
int ar[(int)1e6 + 5] = {0};
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        ar[a]++;
    }

    for(int i = 1e6; i > 0; i--) {
        a = 0;
        for(int j = i; j < (1e6+5); j += i) {
            a += ar[j];
        }
        if(a >= 2) {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
