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
const int MAXN = 1e6+5;


void solve() {
    int n,m,q; cin >> n>> m >> q;
    set<int> linhas, colunas;
    FOR(i,0,q){
        int t; cin >> t;
        if(t ==1){
            int x ,y; cin >> x >> y;
            linhas.insert(x);
            colunas.insert(y);
        }
        else{
            int xi,yi,xf,yf; cin >> xi >> yi >> xf >> yf;

            if((linhas.count(xi) || colunas.count(yi)) && (linhas.count(xf) || colunas.count(yf))){
                cout<< "SIM\n";
            }
          
            else cout<< "NAO\n";

        }
    }

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
