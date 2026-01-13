#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
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
    vi size;

    DSU(int n){
        pai.resize(n+1);
        size.resize(n+1, 1);
        FOR(i,0,n+1) pai[i] = i; //pq começar do indice zero? não é 1-based?
    }

    int find(int x){
        if( pai[x] == x) return x;
        return pai[x] = find(pai[x]); // me explique essa sintaxe a função retornar pai[x] e iguala a recursão ao msm tempo?
    }

    void join(int x, int y){
        x =find(x); y =find(y);
        if ( x == y) return;

        if(size[x] < size[y]) swap(x,y);

        pai[y] = x;
        size[x] += size[y];// pq não é necessário atualizar o tamanho do size[y]
    }

    //nova função
    int tamanho(int x){
        return size[find(x)];
    }
};

void solve() {
    int n, m; cin >> n >>m;
    DSU dsu(n);
    FOR(i,0,m){
        int qts; cin >> qts;
        if(qts){
            int f; cin >> f; qts--;
            FOR(j,0,qts){
                int x; cin >>x;
                dsu.join(f,x);
            }
        }
    }
    FOR(i, 1,n+1){
        cout << dsu.tamanho(i) <<" ";
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
