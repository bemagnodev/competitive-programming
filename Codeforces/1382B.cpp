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

const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n; cin >>n;
    vl a(n); 
    FOR(i,0,n){
        cin >> a[i];
    }
    
    FOR(i,0,n){
        if(a[i] != 1){
            if(i%2==0){
                cout << "First" <<endl;
            }
            else
                cout << "Second" <<endl;
            break;
        }
        else if(i == n-1 && a[i] ==1 ){
             if(n%2==0){
                cout << "Second" <<endl;
            }
            else
                cout << "First" <<endl;
        }
    } 


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
