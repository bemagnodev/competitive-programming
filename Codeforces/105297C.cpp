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
    ll sum;
    ll min_prefix;
};

struct SegTree{
    int n; 
    Node neutro;
    vector<Node> tree;
    int n_original;
    
    Node merge(Node a, Node b){ 
        Node ans;
        ans.sum = a.sum + b.sum;
        ans. min_prefix = min (a.min_prefix, a.sum+b.min_prefix);
        return ans;
    }
    
    SegTree(const vl& a, int norg){  
        neutro.sum = 0;
        neutro.min_prefix = INFLL;
        n = a.size();
        n_original = norg;
        tree.assign(2*n, neutro);

        FOR(i,0,n){
            tree[i+n].sum = a[i];
            tree[i+n].min_prefix = a[i];
        }

        ROF(i,1,n){
            tree[i] = merge(tree[2*i], tree[2*i+1]);  
        }
    }

    void update(int p, ll v){
        p+=n;
        tree[p].sum =v;
        tree[p].min_prefix =v;
        for(; p>1; p>>=1){ 
            int pai = p>>1;

            tree[pai] = merge(tree[pai*2], tree[pai*2+1]); 

        }
    }

     

    int find(int l) {
        int r = l + n_original;  
        ll e = 0;

        l += n; 
        r += n;

        vector<int> right_nodes;

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (e + tree[l].min_prefix < 0) {
                    int curr = l;
                    while (curr < n) {
                        if (tree[2 * curr].min_prefix + e < 0) {
                            curr = 2 * curr; // Desce Esq
                        } else {
                            e += tree[2 * curr].sum;
                            curr = 2 * curr + 1; // Desce Dir
                        }
                    }
                    return curr - n;  
                }
                e += tree[l].sum;
                l++;
            }

            if (r & 1) {
                --r;
                right_nodes.push_back(r);
            }
        }

        reverse(right_nodes.begin(), right_nodes.end());

        for (int node : right_nodes) {
            if (e + tree[node].min_prefix < 0) {
                int curr = node;
                while (curr < n) {
                    if (tree[2 * curr].min_prefix + e < 0) {
                        curr = 2 * curr;
                    } else {
                        e += tree[2 * curr].sum;
                        curr = 2 * curr + 1;
                    }
                }
                return curr - n;
            }
            e += tree[node].sum;
        }

        return -1;
    }
};


void solve() {
    int n, q; cin >> n >> q;
    vl b(n, 0); FOR(i,0,n) cin >> b[i];
    vl c(n, 0); FOR(i,0,n) cin >> c[i];

    int sz =1;
    while(sz< n*2) sz*=2;
    vl d(sz, 0);
    FOR(i,0,n){
        d[i] = b[i]-c[i]; 
        d[i+n] = d[i];
    } 

    SegTree st(d, n);

    while(q--){
        int tp; cin >> tp;
        if(tp ==1){
            int p; cin >> p;p--;
            int k =st.find(p);
            if(k == -1) {
                cout <<k << "\n";
            } else {
                int ans = (k % n) + 1;
                cout << ans << "\n";
            }

        }
       else if (tp == 2){  
            int p; ll v;
            cin >> p >> v; p--;
            ll novo = v - c[p];
            
            b[p] = v;  
            st.update(p, novo);
            st.update(p + n, novo);
        }
        else{  
            int p; ll v;
            cin >> p >> v; p--;
            ll novo = b[p] - v;
            
            c[p] = v; 
            st.update(p, novo);
            st.update(p + n, novo);
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
