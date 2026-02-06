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
    int neutro = 0;

    ll merge_or(ll a, ll b){
        return (a |b);
    
    }
    ll merge_xor(ll a, ll b){
        return (a ^b);
    }

    SegTree(const vl& a){
        n = a.size();
        tree.assign(4*n, neutro);
        build(a, 1,0,n-1);
    }

    int build(const vl& a, int i, int tl, int tr ){
        int nivel_filho;
        if(tl == tr){
            tree[i] = a[tl];
            return 1;
        }
        else{
            int tm = (tl+tr)/2;
             nivel_filho = build(a,2*i,tl, tm);
            build(a,2*i+1,tm+1, tr);

            if(nivel_filho&1){
                tree[i] =merge_or( tree[2*i] , tree[2*i+1]);
            }
            else{
                tree[i] =merge_xor( tree[2*i] , tree[2*i+1]);
            }
        }
        return nivel_filho+1;
    }

    int updt(  int i, int tl, int tr, int p, ll v ){
        if(tl == tr){
            tree[i] =v;
            return 1;
        }

        int tm = (tl+tr)/2;
        int nvl_filho;
        
        if(p <= tm){
            nvl_filho = updt(2*i,tl, tm, p ,v);
        }
        else{
            nvl_filho = updt(2*i+1,tm+1, tr, p ,v);
        }
        if(nvl_filho&1){
            tree[i] =merge_or( tree[2*i] , tree[2*i+1]);
        }
        else{
            tree[i] =merge_xor( tree[2*i] , tree[2*i+1]);
        }
        return nvl_filho +1;

        }

    ll query ( ){
        return tree[1];
    }

    int updt(int p, ll v) { return updt(1,0, n-1, p,v);}
};


void solve() {
    int n,  m; cin >> n >>m ;
    vl a (1<<n);
    FOR(i,0,(1<<n)) cin >> a[i];

    SegTree st(a);

    while(m--){
        int p; ll v; cin >> p >>v; p--;  
        st.updt(p,v);
        cout << st.query() << endl; 
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
