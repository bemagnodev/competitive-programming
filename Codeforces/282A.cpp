#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; 
    cin >> t;  

    int x =0;
    while (t--) {
        string q; cin >> q;
        if(q == "X++" || q == "++X"){
            x++;
        }
        else if(q == "X--" || q == "--X"){
            x--;
        }
    }
    cout << x << endl;

    return 0;
}
