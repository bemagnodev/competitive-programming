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


struct SegTree {
    int n;
    vector<ll> tree;
    ll neutro = 0; 

    ll merge(ll a, ll b) { return a + b; }
     

     SegTree(const vector<int>& a) {
        n = a.size();
        tree.assign(2 * n, neutro);  
        for (int i = 0; i < n; i++) tree[n + i] = a[i];
        
        for (int i = n - 1; i > 0; --i) 
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    void update(int p) {
        p += n;  
        tree[p] = (tree[p] == 1 ? 0 : 1);
        
            
        for (; p > 1; p >>= 1) { 

            int pai = p>>1;
            tree[pai] = merge(tree[pai*2], tree[pai*2+1]);  
        }
    }

    ll find(int k) {
        int p = 1;

        while (p < n){
            // esquerdo
            if(tree[2*p]> k){
                p*=2;
            }
            // filho esta na direita
            else{
                k-=tree[2*p];
                p= p*2+1;
            }
            
        }
        return p-n;
    }


};

void solve() {
    int n, m; cin >> n >> m;
    int size  =1;
    while(size < n) size*=2;
    
    vi a(size, 0); FOR(i,0,n) cin >> a[i];
    SegTree st(a);

    while(m--){
        int type, x; cin >> type >> x;
        if(type == 1){
            st.update(x);
        }
        else{
            cout << st.find(x) << "\n";
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
