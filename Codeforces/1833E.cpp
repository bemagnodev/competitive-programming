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
const int INF = 1e9;
const ll INFLL = 4e18;

struct DSU{
    vi pai, sz;
    int n;
    int components;


    DSU(int _n) : n(_n), components(_n), sz(_n, 1), pai(_n){// pq usar o _n?
        FOR(i,0,n) pai[i] = i;
    }

    int find (int x){
        if(pai[x] == x) return x;
        return pai[x] = find(pai[x]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[b] > sz[a]) swap(a,b);

        components--;
        pai[b] = a;
        sz[a]+=sz[b];
    }
};// esta boa minha implementação de dsu?

void solve() {
    int n; cin >> n;
    vector<set<int>> grau(n);
    DSU dsu(n);
    
    FOR(a,0,n){
         int b; cin >> b; b--;
         dsu.unite(a, b);
         grau[a].insert(b);
         grau[b].insert(a);
    }

    int caminho = 0;
    vi caminhos(n, 0);

    FOR(i,0,n){
        if(grau[i].size() ==1){
            caminhos[dsu.find(i)] = 1;
        }
    }

    FOR(i,0,n){
        caminho += caminhos[i];
    }

    int mx = dsu.components;
    int ciclos = mx - caminho;
    int mn = (caminho> 0 ? ciclos+1 : ciclos);

    cout << mn << " " << mx << "\n";


     
}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
