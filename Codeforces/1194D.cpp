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

 

int k; 
void solve() {
    ll n, k;
    cin >> n >> k;

    if (k % 3 != 0) {
        if (n % 3 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }  else {
    if (n == k) {
        cout << "Alice" << endl;
    } else if (n < k) {
        if (n % 3 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    } else { // n > k
        ll rem = n % (k + 1);
        if (rem == k) {
            cout << "Alice" << endl;
        } else if (rem % 3 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}
