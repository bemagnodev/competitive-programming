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
    vi tree;
    int neutro = INF;

    int merge(int a, int b) {return min(a,b);}
    
    SegTree(const vi& a){
        n = a.size();
        tree.assign(4*n, neutro);
        build(a, 1, 0, n-1);
    }

    void build (const vi& a, int i, int tl , int tr){
        if(tl ==tr) tree[i] = a[tl];
        else{
            int tm = (tl+tr)/2;
            build(a,2*i,tl, tm);
            build(a,2*i+1,tm+1, tr);

            tree[i] = merge( tree[2*i], tree[2*i+1]);
        }

    }

    void update ( int i, int tl , int tr, int p, int v){
        if(tl ==tr) tree[i] = v;
        else{
            int tm = (tl+tr)/2;
            if(p <= tm)
                update( 2*i, tl, tm, p , v);
            else
                update( 2*i+1, tm+1, tr, p , v);
 
            tree[i] = merge( tree[2*i], tree[2*i+1]);
        }

    }

    int query ( int i, int tl , int tr, int l, int r){
        if(l > r) return neutro;
        //caso base 
        if(tl == l && tr ==r) return tree[i];

        int tm = (tl+tr)/2;
        return merge(
            query(2*i, tl, tm, l, min(tm, r)),
            query(2*i+1, tm+1, tr, max(tm+1, l), r)
        );

    }

    void update (   int p, int v){
          update(1, 0, n-1, p, v);
    }
    int query (   int r, int l){
        return  query(1, 0, n-1, r, l);
    }
};


void solve() {
    int n, q ; cin >> n >> q;
    vi a(n); FOR(i,0,n) cin >> a[i];
    SegTree st(a);
    while(q--){
        int type, x, y; cin >> type >> x >>y;
        if(type==2){  
            cout << st.query(x, y-1)<< "\n";
        }
        else{
            st.update(x,y);
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
