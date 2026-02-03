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
    int neutro = 0;
    vi tree;

    int merge(int a, int b){ return a+b;}

    SegTree(const vi& a){  
        n = a.size();
        tree.assign(2*n, 1);

        ROF(i,1,n){
            tree[i] = merge(tree[2*i], tree[2*i+1]);
        }
 
    }

    void update(int p){
        p+=n;
        tree[p] =0;

        for(; p>1; p>>=1){ 
            tree[p>>1] = merge(tree[p], tree[p^1]); 

        }
    }

    int query(int l, int r){
        int res = neutro;
        for(l += n, r+=n; l<r; l>>=1, r>>=1){
            if(l&1) res = merge(res, tree[l++]);

            if(r&1) res = merge(res,tree[--r] );  
        }
        return res;    
    }

    int find(int x){
        // if( tree[1] < x) return -1; nao precisa pra questao
        int p = 1;
        while (p<n){
            if(tree[2*p] >= x){
                p*=2; //esq
            }
            else{
                x-=tree[2*p];
                p = 2*p+1; //direita
            }
        }
        return p-n ;
    }
        
};


void solve() {
    int n; cin >> n; 
    int sz =1 ; while(sz<n) sz*=2;
    vi a(sz, 0);
    
    FOR(i,0,n){
        cin >> a[i];
    }

    SegTree st(a);
    FOR(i,0,n){
        int x; cin >> x;
        int k = st.find(x);
        cout << a[k] << " ";
        st.update(k);
    }
    cout << "\n" ;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
