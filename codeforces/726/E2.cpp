#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int n, k;

vector<int> z_func(string &s) {
    int n = s.size(), L = -1, R = -1;
    vector<int> z(n);
    z[0] = n;
    for(int i = 1; i < n; i++) {
        if(i <= R)
            z[i] = min(z[i - L], R - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if(i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

void finish(int m) {
    for(int i = 0; i < k; i++)
        cout << s[i % m];
    cout << '\n';
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> s;
    auto z = z_func(s);

    int cur = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] > s[i % cur])
            finish(cur);
        if(s[i] < s[i % cur]) {
            cur = i + 1;
            continue;
        }
        int off = i - cur + 1;
        if(off == cur) {
            cur = i + 1;
            continue;
        }
        if(z[off] < cur - off) {
            if(cur + off + z[off] >= k) {
                cur = i + 1;
                continue;
            }
            if(s[off + z[off]] > s[z[off]])
                cur = i + 1;
            continue;
        }
        if(z[cur - off] < off) {
            if(2 * cur + z[cur - off] >= k) {
                cur = i + 1;
                continue;
            }
            if(s[cur - off + z[cur - off]] < s[z[cur - off]])
                cur = i + 1;
            continue;
        }
        cur = i + 1;
    }

    finish(cur);
}