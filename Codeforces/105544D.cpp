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

void solve() {
    int n,m; char d1, d2;
    cin >> n >> m >> d1 >> d2;
    vector<vector<char>> mat(n, vector<char>(m));

    FOR(i,0,n){
        FOR(j,0,m){
            char c; cin >> c;
            if(c == '.') c='0';
            mat[i][j] = c;
        }
    }
    
    FOR(i,0,n){
        FOR(j,0,m){
            if(mat[i][j] == 'V'){
                FOR(dx,-1,2){
                    FOR(dy, -1,2){
                        int nx = i+dx;
                        int ny = j+dy;
                        
                        if(nx >= 0 && nx < n && ny >=0 && ny < m){
                                //lados
                                if(abs(dx)+ abs(dy) == 1){
                                    mat[nx][ny] = max( mat[nx][ny], d1);
                                }
                                // diagonais
                                else {
                                    mat[nx][ny] = max( mat[nx][ny], d2);
                                }
                        }
                    }
                }
            }
        }
    }

     FOR(i,0,n){
        FOR(j,0,m){
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    FOR(i,0,t){
        cout << "Airplane #" << i+1 << ":\n";
        solve(); 
        cout << endl;
    } 
    return 0;
}
