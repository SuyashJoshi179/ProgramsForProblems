#include <bits/stdc++.h>
using namespace std;

unordered_set<int> us;

int main() {
    us.reserve(200005);
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        us.insert(a);
    }
    cout<<us.size();
    return 0;
}
