#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int ans = 0, n = s.length(), m = t.length();
    
    vector<int> lps(m);
    lps[0] = 0;
    int j = 0, i;
    for(i = 1; i < m; i++) {
        if(t[i] == t[j]) lps[i] = ++j;
        else {
            while(t[i] != t[j]) {
                if(j == 0) break;
                else j = lps[j-1];
            }
            lps[i] = j;
        }
    }
    
    i = 0; j = 0;
    while(i < n) {
        if(s[i] == t[j]) i++, j++;
        if(j == m) {
            ans++;
            j = lps[j-1];
        }
        else if(i < n && s[i] != t[j]) {
            if(j == 0) {
                i++;
            } else {
                j = lps[j-1];
            }
        }
    }
    cout<<ans;
    return 0; 
}
