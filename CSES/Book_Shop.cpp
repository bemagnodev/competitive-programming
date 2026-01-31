#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
#define pb push_back
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;  
const int INF = 1e9;
const ll INFLL = 4e18;

void solve() {
    int n,  x; cin >> n >> x;
    vi prices(n), pages(n);

    FOR(i,0,n) cin >> prices[i];
    FOR(i,0,n) cin >> pages[i];

    
    vl dp(x+1, 0); // dp[p] = paginas max. que consigo alcançar com preço p, até o processamento atual
    
    FOR(i,0,n){// itera por cada item
        ROF(p,0,x+1){ // itera por indice da dp
            int preco = prices[i];
            int pag = pages[i];
            if(p-preco >=0){
                dp[p]= max (dp[p], dp[p -preco] + pag); 
            }
             
        }
    }

    cout << dp[x] << endl;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
