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

const int SZ = 2;  

struct Matrix {
    ll mat[SZ][SZ];

    
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }

    static Matrix identity() {
        Matrix res;
        for (int i = 0; i < SZ; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for (int i = 0; i < SZ; i++) {
            for (int j = 0; j < SZ; j++) {
                for (int k = 0; k < SZ; k++) {  
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix matPow(Matrix base, ll exp) {
    Matrix res = Matrix::identity();
    while (exp > 0) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;
    Matrix mat;
    mat.mat[0][0]=3;
    mat.mat[0][1]=1;
    mat.mat[1][0]=1;
    mat.mat[1][1]=3;
    Matrix ans = matPow(mat, n);
    cout << ans.mat[0][0] << endl;

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
