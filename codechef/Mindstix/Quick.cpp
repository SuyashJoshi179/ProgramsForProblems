#include <bits/stdc++.h>
using namespace std;

void quicksort(int ar[], int n) {
    int sl[n+1], sr[n+1];
    int p = 0;
    sl[p] = 0; sr[p] = n;
    p++;
    while(p) {
        p--;
        int l = sl[p], r = sr[p];
        cout<<l<<" "<<r<<endl;
        if(l+1 >= r) continue;
        int pivot = r-1;
        int it = l-1;
        for(int i = l; i < r; i++) {
            if(ar[i] <= ar[pivot]) {
                it++;
                // swap i and it
                int temp = ar[i];
                ar[i] = ar[it];
                ar[it] = temp;
            }
        }
        sl[p] = l; sr[p] = it;
        p++;
        sl[p] = it + 1; sr[p] = r;
        p++;
    }
}

int main() {
    int ar[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = 10;
    quicksort(ar, n);
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
