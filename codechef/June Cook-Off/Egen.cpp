#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}
int main() {
    cout<<1<<"\n";
    int n = rnd(1, 100);
    cout<<n<<endl;
    for(int i = 0; i<n; i++) {
        cout<<rnd(1, 1000)<<" ";
    }
    cout<<"\n";
    for(int i = 0; i<n; i++) {
        cout<<rnd(1, 1000)<<" ";
    }
    cout<<"\n";
}