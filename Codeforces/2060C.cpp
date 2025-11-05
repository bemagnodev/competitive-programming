#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);  
    vi f(max(n, k) + 5);
    FOR(i,0,n) {
        cin >> a[i];
        f[a[i]]++;
        
    }
    ll pares = 0;
    // FOR(i,0,n) cerr << f[i] << " ";
    FOR(i,1,(k/2)+1){ 
        if(f[i] && f[k-i]){
            if(i != k-i){
                // cerr << "entrou: "<< i <<endl;
                pares += min(f[i], f[k-i]);
            }
            else{
                // cerr << "entrou2: "<< i <<  endl;
                pares += f[i]/2;
            }
        }
    }

    cout << pares << endl; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}
