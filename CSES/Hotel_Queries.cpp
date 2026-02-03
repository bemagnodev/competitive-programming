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
const int INF = 2e9;
const ll INFLL = 4e18;

struct SegTree{
    int n; 
    vi tree;
    int neutro = -INF;

    int merge(int a, int b){ return max(a,b);}

    SegTree(const vi& a){
        n = a.size();
        tree.assign(2*n, neutro);
        
        FOR(i,0,n) tree[i+n] = a[i];

        ROF (i,1,n){
            tree[i] = merge(tree[2*i] ,tree[2*i +1]);  
        }
        
    }

    void update(int p, int r){
        p+=n;
        int value = tree[p] -r;
        tree[p] = value;

        for(; p>1; p>>=1){
            tree[p>>1] = merge(tree[p], tree[p^1]); // como tem o padding, não preciso me preocupar quanto a ordem dos irmãos, certo?
        }
    }

    int find(int x){ // analogo a busca binaria
        if( x > tree[1]) return -1; // não tem nenhum quarto disponivel
        int p = 1;

        while(p <n){ // enquanto nao for folha
            if(tree[2*p] >= x){// existe quarto vago ao lado esquerdo
                p*=2;
            }
            else{ //vamos para a direita
                p = 2* p +1;
            }
        }
        return p-n;
    }
};

void solve() {
    int n, m; cin >> n >>m;
    int sz = 1;
    while(sz< n) sz*=2;
    
    vi hoteis(sz, 0);
    FOR(i,0,n) cin >> hoteis[i];
    SegTree st(hoteis);

    vi ans;

    while (m--){
        int r; cin >> r;
        
        int p = st.find(r); // p é a primeira posição em que o num de hoteis é maior ou igual a r
        
        if(p == -1) {
            ans.pb(0);
        }
        else{
            ans.pb(p+1);//1-based
            st.update(p, r);
        }

    }
    for(int a : ans){
        cout << a << " ";
    }
    cout << "\n";

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
