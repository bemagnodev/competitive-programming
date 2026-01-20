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

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

ll bfs(pii u, int n, int m, vector<vi>& adj ){
    queue<pii> q;
    q.push(u);
    int d = 0;
    d += adj[u.st][u.nd];
    adj[u.st][u.nd] = 0;

    while(!q.empty()){
        int x =  q.front().st;
        int y =  q.front().nd;
        q.pop();

        FOR(i,0,4){
            int nx = x+dx[i];
            int ny = y +dy[i];

            if(adj[nx][ny] != 0){
                d += adj[nx][ny]; 
                adj[nx][ny] = 0;    
                q.push({nx, ny});

            }
        }
    }
    return d;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n+2, vi(m+2,0));
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            cin>> adj[i][j];
        }
    }
     ll ans = 0;
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            if(adj[i][j] != 0){
               ans = max(ans, bfs({i,j},n, m ,adj));

            }
        }
    }

    cout << ans << endl;


}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
