#include <bits/stdc++.h>

using namespace std;
using ll = long long;   

int n; ll m;

bool check(ll x, vector<int> alturas){
    ll soma = 0;
    for(int y : alturas){
        if(y > x) soma += (y-x);
    }

    // cerr << soma << endl;
    return( soma >= m);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    
    cin >> n;
    cin >> m;

    vector<int> alturas(n);
    for(int i =0; i< n; i++) cin >> alturas[i];

    ll l = 0; ll r = 2e9;
    ll resp;
    while(l <=r){
        ll mid = l +(r-l)/2;
        if(check(mid, alturas)){ // soma >= m
            resp = mid;
            l = mid +1;
        }
        else{ //soma < m
            r = mid -1;
        }
    }
    
    cout << resp << endl;
            
    
    return 0;

}
