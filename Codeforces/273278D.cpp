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
    int neutro  = -INF;

    int merge(int a, int b){
        return max(a,b);
    }

    SegTree(const vi& a){
        n = a.size();
        tree.assign(2*n, neutro);

        FOR(i,0,n) tree[i+n] = a[i];
        ROF(i,0,n) tree[i] = merge(tree[2*i], tree[2*i+1]);
    }

    void update(int p, int v){
        p+= n;
        tree[p] = v;

        for(; p> 1; p>>=1){
            tree[p>>1] = merge(tree[p] , tree[p^1]);
        }
    }

    int query(int l, int r){
        int ans = 0;
        for( r+=n, l+=n; r>l; r/=2, l/=2){
            if(l&1) ans =merge(ans, tree[l++]);
            if(r&1) ans =merge(ans, tree[--r]);
        }
        return ans;
    }

    int find (int x, int l){
        // if (tree[1] < x) return -1;
        int r = n;

        for( r+=n, l+=n; r>l; r/=2, l/=2){
            if(l&1){
                if(tree[l] >= x){
                    while (l < n) {
                        if(tree[l*2] >=x ){ // indice esta no filho a esquerda
                            l<<=1;
                        }
                        else{ // indice esta no filho a direita
                            l = 2*l +1;
                        }
            
                    }
                    return l-n;

                }
                l++;
            }
        }
        return -1;


    
    }
};

void solve() {
    int n, m ; cin >> n >>m;
    int sz = 1;
    while(sz< n) sz*=2;
    vi a(sz, -INF); FOR(i,0,n) cin >> a[i];

    SegTree st(a);

    while(m--){
        int type; cin >> type;
        if(type ==1){
            int i, v; cin >> i >> v;
            st.update(i,v);
        }
        else{
            int x, l; cin >> x >> l;
            cout << st.find(x, l) << "\n";
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
