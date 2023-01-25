#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0, curr = 0;
    char prev = 'z';
    string s;
    cin >> s;
    for(char c: s) {
        if(c == prev) curr++;
        else {
            // cout<<prev<<" "<<c<<" "<<curr<<endl;
            ans = max(ans, curr);
            curr = 0;
        }
        prev = c;
    }
    ans = max(ans, curr);
    cout<<(ans+1);
    return 0;
}
