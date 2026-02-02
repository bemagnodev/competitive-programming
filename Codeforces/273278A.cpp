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

struct Node{
    ll seg; 
    ll pref, suff, sum;
};

struct SegTree{
    int n; 
    vector<Node> tree;
    Node neutro;
    
    Node merge( Node a, Node b){
        Node ans;
        ans.sum = a.sum + b.sum;
        ans.pref = max(a.pref, a.sum+ b.pref);
        ans.suff = max(b.suff, b.sum+ a.suff);

        ans.seg = max(a.seg, b.seg);
        ans.seg = max(ans.seg, a.suff+b.pref);

        return ans;
    }

    SegTree(const vl& a){
        n = a.size();
        neutro.pref =0;
        neutro.seg =0;
        neutro.suff =0;
        neutro.sum =0;

        tree.assign(2*n, neutro);

        FOR(i,0,n){
            tree[i+n].sum = a[i];
            if(a[i]>0){ // pq só se for maior que zero?
                tree[i+n].seg = a[i];
                tree[i+n].pref = a[i];
                tree[i+n].suff = a[i];
            }
        }

        ROF(i, 1, n){

            tree[i] = merge(tree[2*i], tree[2*i+1]);
        }
    }

    void update(int p, ll value){
        p +=n;
        tree[p] = neutro;
        tree[p].sum = value;
            if(value>0){ // pq só se for maior que zero?
                tree[p].seg = value;
                tree[p].pref = value;
                tree[p].suff = value;
            }

        for(; p>1; p>>=1){
            int pai = p>>1;
            tree[pai] = merge(tree[pai*2], tree[pai*2+1]);
        }
    }

    ll query(int l, int r){
        return tree[1].seg;
        // for(l+=n, r+=n; r>l; l>>=1, r>>=1){

        // }
    }



};

void solve() {
    int n, q ; cin >> n >> q;
    int size = 1;
    while (size < n) size *= 2;
    
    vl a(size, 0);
    
     FOR(i,0,n) cin >> a[i];
    SegTree st(a);
    cout << st.query(1,n+1) << "\n";
    while(q--){
        int   x, y; cin  >> x >>y;
        st.update(x,y);
        cout << st.query(1,n+1) << "\n";

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
