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
    int neutro  =0;

    int merge(int a, int b){
        return a+b;
    }

    SegTree(const vi& a){
        n = a.size();
        tree.assign(2*n, neutro);
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
};

 
void solve() {
    int n; cin >> n;
    vi a(2*n);
    FOR(i,0,2*n){
        cin >> a[i];
        
    } 
    vi start_pos(n+1, -1);
    vi ans(n+1, 0);
    SegTree st(a);

    FOR(i,0,2*n){
        int x = a[i];
        if(start_pos[x] == -1){
            start_pos[x] = i;
        }
        else{
            //query -> resposta
            ans[x] = st.query(start_pos[x], i);

            //update na arvore no start_pos[x]
            st.update(start_pos[x], 1);
        }
    }

    FOR(i,1,n+1){
        cout << ans[i] << " ";
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
