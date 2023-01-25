#include <bits/stdc++.h>
using namespace std;

unordered_set<int> us;

int main() {
    int n, a;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end());
    if(n == 0) cout<<0;
    else {
        a = 1;
        for (int i = 1; i < n; i++)
        {
            if(v[i] != v[i-1]) a++;
        }
        cout<<a;
    }
    return 0;
}
