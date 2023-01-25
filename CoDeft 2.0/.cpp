#include <bits/stdc++.h>
using namespace std;

int func(int i) {
    if(i < 4) return i-1;
    if(i%2) return 3;
    return 2;
}

int main() {
    for(int i = 1; i < 10; i++) {
        cout<<i<<" "<<func(i)<<endl;
    }
    return 0;
}
