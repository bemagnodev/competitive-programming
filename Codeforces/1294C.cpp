#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;
#define deb(k) cerr << #k << ": " << k << "\n";

const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n; cin >> n;
    int a , b =-1, c =-1;
    int aux = n;
    for(int i = 2; i * i <= n; i++){
        deb(i);
        if(aux % i ==0){
            a= i;
            aux/=i;
            break;
        }
    }
    for(int i = a+1; i * i <= n; i++){
        if(aux % i ==0){
            b= i;
            aux/=i;
            c = n/ (a*b);
            if(c == a || c ==b) break;
            cout << "YES\n";
            cout << a << " " << b << " " << c << endl;
            return;
        }
    }
    cout << "NO\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}
