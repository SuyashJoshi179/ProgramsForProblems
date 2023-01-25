#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 0; i < 100; i++)
    {
        for (int j = i/2; j > 0; j--)
        {
            cout<<i/j<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}
