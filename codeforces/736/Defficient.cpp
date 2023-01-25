#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second 
#define all(x)          x.begin(),x.end()
#define rall(x)         x.rbegin(),x.rend()
#define loop(i,m,n)     for(ll i=m; i<n; i++)
#define rloop(i,m,n)    for(ll i=m; i>=n; i--)
#define print(x)        for(auto t : x){cout << t << " ";}cout <<"\n";
#define printnl(x)      for(auto t : x)cout << t <<"\n";

#define MOD  1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef pair<int,int>   pii; 
typedef vector<int>     vi;   
typedef vector<ll>      vl;  
typedef vector<double>  vd;  
typedef vector<char>    vc;  
typedef vector<string>  vs;  
typedef set<int>        si;  
typedef set<ll>         sl;  
typedef set<double>     sd;  
typedef set<char>       sc;  
typedef set<string>     ss;  
typedef map<int,int>    mi;  
typedef map<ll,ll>      ml;  
typedef map<double,int> md;  
typedef map<char,int>   mc;  
typedef map<string,int> ms;  

// **************************************************************************************
ll a[200005], b[200005], n,k;

bool check(ll m){
    ll pre[n], suf[n];
    for(int i=1; i<=k; i+=m){
        int h = min(k,i+m-1);
        pre[i] = b[i];
        for(int j=i+1; j<=h; j++){
            pre[j] = __gcd(b[j], pre[j-1]);
        }
        suf[h] = b[h];
        for(int j=h-1; j>=i; j--){
            suf[j] = __gcd(b[j], suf[j+1]);
        }
    }
    for(int i=1; i+m-1<=k; i++){
        if(__gcd(suf[i], pre[i+m-1])!=1)return true;
    }
    return false;
}

void solve(){
    cin>>n;
    k=n-1;
    loop(i,0,n)cin>>a[i];
    if(n==1){
        cout<<n<<"\n";
        return;
    }
    if(n==2 && abs(a[1]-a[0])!=1){
        cout<<n<<"\n";
        return;
    }
    loop(i,1,n) b[i] = abs(a[i]-a[i-1]);
    
    ll l=1, r=k, ans=1;
    while(l<=r){
        ll m = (l+r)/2;
        if(check(m)) {
            l=m+1;
            ans = max(ans, m+1);
        }
        else r=m-1;
    }
    cout<<ans<<"\n";
    return;
}

int main(){
    fast

    int tc = 1;
    cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}
