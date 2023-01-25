#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n = 0, ans = 0, prev, curr;
    cin >> n;
    cin >> prev;
    for(int i = 1; i < n; i++) {
        cin>>curr;
        // cout<<prev<<" "<<curr<<endl;
        if(prev > curr) ans += (prev - curr); 
        else prev = curr;
    }
    cout<<ans;
    return 0;
}
