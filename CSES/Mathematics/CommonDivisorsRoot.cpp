#include <bits/stdc++.h>
using namespace std;
int ar[(int)1e6 + 5] = {0};
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n, a;
    ar[1] = 2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        for(int j = 2; j*j <= a; j++) {
            if(a%j == 0) ar[j]++, ar[a/j] += (j == a/j ? 0 : 1);
        }
        ar[a]++;
    }

    a = 1e6 + 4;
    while(ar[a] < 2) a--;
    cout<<a<<endl;
    return 0;
}
