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
const int INF = 1e9+ 7;
const ll INFLL = 4e18;

struct SegTree{
    int n; 
    vl tree;
    ll neutro = 0;

    ll merge (ll a, ll b) { return a + b;}

    SegTree(const vl& a){
        n = a.size();
        tree.assign(4*n, neutro);
        build(a, 1, 0, n-1 );
    }

    void build(const vl& a, int i, int tl, int tr){
        // caso base
        if(tl == tr){ // é folha
            tree[i] = (ll)a[tl];
        }
        else{
            int tm = (tl+tr)/2;
            //esq
            build(a, 2*i,tl, tm);   
            //dir
            build(a, 2*i+1,tm+1, tr);

            tree[i] = merge(tree[2*i], tree[2*i+1]);
        }
    }

   void updt(int i =1, int tl= 0, int tr =-1, int p, ll v) {
        if (tr == -1) tr = n - 1;
        //acho
        if(tl == tr) tree[i] = v;
        else{
            int tm = (tl+tr)/2;
            if(p <= tm)//esq
                updt(2*i,tl, tm, p, v);   
            //dir
            else
                updt(2*i+1,tm+1, tr, p, v);   

            tree[i] = merge(tree[2*i], tree[2*i+1]);
        }
    }
     ll qry(int i=1, int tl = 0, int tr = -1, int l, int r) {
        if (tr == -1) tr = n - 1;
        if( l> r)return neutro; //garante que se l > tl retorne?
        //caso base
        if(l == tl && r == tr) return tree[i];

        int tm = (tl+tr)/2;
        return merge(
           qry(2 * i, tl, tm, l, min(r, tm)),
            qry(2 * i + 1, tm + 1, tr, max(l, tm + 1), r)
        );

    }

    
    void updt(int p, int x) { updt(1, 0, n - 1, p, x); }
    ll qry(int l, int r) { return qry(1, 0, n - 1, l, r); }


};    


void solve() {
    int n, q ; cin >> n >> q;
    vl a(n); FOR(i,0,n) cin >> a[i];
    SegTree st(a);
    while(q--){
        int type; cin >> type;
        if(type==2){  
            int l, r; cin >> l >> r;
            cout << st.qry(l, r-1)<< "\n";
        }    
        else{
            int p; ll v; cin >> p >> v,

            st.updt(p,v);
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
