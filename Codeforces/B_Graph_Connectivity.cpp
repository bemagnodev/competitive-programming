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



void dfs(int u , vector<bool>& visitado, vector<vi>& adj ){
    visitado[u] = true;
    
    for (int v : adj[u]) {
        if (!visitado[v]) {
            dfs(v, visitado, adj);
        }
    }
}

void solve() {
    string s;
    char c; cin >> c; 
    cin.ignore();
    int n = c -'A'+1;
    vector<vi> adj(n);
     while(getline(cin,s) && s!=""){
        int u = s[0]-'A';
        int v = s[1]-'A';
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> visitado(n, false);

    int comp = 0;

    FOR(i,0,n){
        if(!visitado[i]){
            dfs(i, visitado, adj);
            comp++;
        }
    }

    cout << comp << endl;
}

int main() {
    fastio;
    int t =1; 
    cin >> t; 
    cin.ignore(); 
    cin.ignore(); 
    while (t--) {
        solve(); 
        if(t) cout << "\n"; 
    }
    return 0;
}

