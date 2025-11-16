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

void solve() {
    int n; cin >> n;
    vl datas(n);

    FOR(i,0,n){
        ll d,m,a; cin >> d >> m >> a;
        ll data = d + 30*(m-1) + 360*a;
        datas[i] = data;
        // deb(datas[i]);
    }
    // sort(all(datas));
    // ll maior = datas[n-1] - datas[0];
    ll maior = 0;
    ll menor= INF;
    FOR(i,0,n-1){
        if(datas[i+1] - datas[i] < menor && datas[i+1] - datas[i] != 0 ){
            menor = datas[i+1] - datas[i];

        }
        if(datas[i+1] - datas[i] > maior && datas[i+1] - datas[i] != 0 ){
            maior = datas[i+1] - datas[i];

        }
    }
    cout << menor << " " << maior<< endl;

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
