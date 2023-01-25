#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int ar[s1.length() + 1][s2.length()+1];
    for(int i = 0; i <= s1.length(); i++) {
        ar[i][0] = i;
    }
    for(int i = 0; i <= s2.length(); i++) {
        ar[0][i] = i;
    }
    for(int j = 1; j <= s2.length(); j++) {
        for(int i = 1; i <= s1.length(); i++) {
            ar[i][j] = min(ar[i][j-1] + 1, min(ar[i-1][j] + 1, ar[i-1][j-1] + (s1[i-1] != s2[j-1])));
        }
    }
    // for(int i = 0; i <= s1.length(); i++) {
    //     for(int j = 0; j <= s2.length(); j++) {
    //         cout<<ar[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<ar[s1.length()][s2.length()];
    return 0;
}
