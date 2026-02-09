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
    vl tree;
    vl lazy;
    ll neutro =INF;

    ll merge(ll a, ll b) {return min(a,b);}
    int left(int i ) { return 2*i;}
    int right(int i ) { return 2*i+1;}

    SegTree(const vl& a){
        n = a.size();
        tree.assign(4*n, neutro);
        lazy.assign(4*n, -1);
        build(a, 1, 0, n-1);
    }
    void build(const vl& a, int i, int tl, int tr){
        if (tl == tr) tree[i] = a[tl];
        else{
            int tm = (tl+tr)/2;
            build(a, left(i), tl, tm);
            build(a, right(i), tm+1, tr);

            tree[i] = merge(tree[left(i)], tree[right(i)]);
        }
    }

     void push(int i, int tl, int tr) {
        if (lazy[i] != -1) {
            int tm = (tl + tr) / 2;
            
            tree[left(i)] = lazy[i];
            lazy[left(i)] = lazy[i];
            
            tree[right(i)] = lazy[i] ;
            lazy[right(i)] = lazy[i];
            
            lazy[i] = -1;
        }
    }

    void update(int i, int tl, int tr, int l, int r, ll v) {
        if (l > r) return;

        if (l == tl && r == tr) {
            tree[i] =v  ;
            lazy[i] = v;
        } else {
            push(i, tl, tr);
            int tm = (tl + tr) / 2;
            
            update(left(i), tl, tm, l, min(r, tm), v);
            update(right(i), tm + 1, tr, max(l, tm + 1), r, v);
            
            tree[i] = merge(tree[left(i)], tree[right(i)]);
        }
    }
    ll query(int i, int tl, int tr, int l, int r){
        if( l > r) return neutro;

        if(l == tl && r == tr){
           return tree[i];
        }
        else{
            push(i,tl, tr);
            int tm = (tl+tr)/2;

           return merge( 
                query(left(i), tl, tm, l, min(r , tm)),
                query(right(i), tm+1, tr, max(l, tm+1), r)
           );
        }
    }

    ll query(int l, int r){ return query(1,0, n-1, l,r);}
    void update(int l, int r, ll v){  update(1,0, n-1, l,r, v);}
};



void solve() {
    int n, m; cin >> n >> m;
    vl a(n,0);
    SegTree st(a);

    while (m--)
    {
        int tp; cin >> tp;
        if(tp == 1){
            int l, r; ll v; cin >> l >> r >>v; r--;
            st.update(l,r,v);
        }
        else{
            int l, r; cin >> l >> r;r--;
            cout << st.query(l ,r) << endl;
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
