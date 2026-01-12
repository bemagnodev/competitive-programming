#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n,soma =0; cin >> n;
    vi a(n+1);
    FOR(i,1,n+1){
        cin >> a[i];
    }
    FOR(i,1,n){
        soma+= abs(a[i] -a[i+1]);
    }
    int maior  =0;
    FOR(i,1,n+1){
        int atual = 0;
        if(i -1> 0) atual += abs(a[i] - a[i-1]);
        if(i +1<= n) atual += abs(a[i] - a[i+1]);
        int delta = 0;
        if(i ==1) delta = 0;
        else if(i ==n) delta = 0;
        else delta = abs(a[i-1]- a[i+1]);
        delta =atual - delta;
        maior = max(maior, delta);
    }
   
    cout << soma - maior<<endl; 



}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
