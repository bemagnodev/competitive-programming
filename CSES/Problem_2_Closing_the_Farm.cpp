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
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

struct DSU{
    vi pai;
    vi sz;
    int components;
    DSU(int n){
        sz.assign(n+1,1);
        pai.resize(n+1);
        FOR(i,1,n+1) pai[i] =  i;
        components = n;
    }

    int find( int x){
        if(pai[x] == x) return x;
        return pai[x] = find(pai[x]);
    }

    void join(int a , int b){
        a = find(a);
        b = find( b);
        if(a==b) return;

        if(sz[b] >sz[a]) swap(a,b);
        pai[b] =a;
        sz[a]+=sz[b];
        components--;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n+1);
    vi removed;
    FOR(i,0,m){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR(i,1,n+1){
        int r; cin >> r;
        removed.pb(r);
    }
    DSU dsu(n);

    
    vector<bool> ativos(n+1,false);
    vector<bool> rev_ans(n);

    int abertos = 0;

    ROF(i,0,n){
        int rem = removed[i];
        ativos[rem] = true;
        abertos++;

        for(int viz : adj[rem]){
            if(ativos[viz]){
                dsu.join(rem, viz);
            }
        }
        // 1 componente
        if(n-abertos+1 == dsu.components){
            rev_ans[i] = true;
        }
        else rev_ans[i] = false;
    }

    FOR(i,0,n){
        if(rev_ans[i]) cout<< "YES\n";
        else cout <<"NO\n";
    }

}

int main() {
    fastio;
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
