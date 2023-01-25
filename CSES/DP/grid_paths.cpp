#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m = 1e9 + 7;
    cin>>n;
    int grid[n][n];
    char ch;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin >>ch;
            grid[i][j] = ch == '*' ? -1 : 0;
        }
    }
    if(grid[0][0] == -1) {
        cout<<0;
        return 0;
    };
    grid[0][0] = 1;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(grid[i][j] != -1) {
                if(i && grid[i-1][j] != -1)  grid[i][j] += grid[i-1][j], grid[i][j] %= m;
                if(j && grid[i][j-1] != -1)  grid[i][j] += grid[i][j-1], grid[i][j] %= m;
            }
        }
    }
    cout<<(grid[n-1][n-1] == -1 ? 0 : grid[n-1][n-1]);
    return 0;
}
