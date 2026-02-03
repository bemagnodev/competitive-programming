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
    ll n; 
    ll neutro = 0;
    vl tree;

    ll merge(ll a, ll b){ return a+b;}

    SegTree(const vl& a){  
        n = a.size();
        tree.assign(2*n, neutro);

        FOR(i,0,n) tree[i+n] = a[i];

        ROF(i,1,n){
            tree[i] = merge(tree[2*i], tree[2*i+1]);  
        }
    }

    void update(ll p, ll v){
        p+=n;
        tree[p] =v;

        for(; p>1; p>>=1){ 
            tree[p>>1] = merge(tree[p], tree[p^1]); 

        }
    }

    ll query(ll l, ll r){
        ll res = neutro;
        for(l += n, r+=n; l<r; l>>=1, r>>=1){
            if(l&1) res = merge(res, tree[l++]);

            if(r&1) res = merge(res,tree[--r] );  
        }
        return res;    
    }
};

void solve() {
    ll n, q; cin >> n >> q;
    vl a(n);
    FOR(i,0,n){
        cin >> a[i];
    }

    SegTree st(a);

    while(q--){
        ll tp; cin >> tp;
        ll l, r; cin >> l >> r;
        if(tp ==1){
            st.update(l-1,r);
        }
        else {
            cout << st.query(l-1,r) << "\n";
             

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
