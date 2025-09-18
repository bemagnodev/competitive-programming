#include <bits/stdc++.h>

using namespace std;
using ll = long long;  


const int MAXN = 1e5 +5;
int n, k;


bool check(ll x, vector<ll> alturas){
    int i_menor;
    for(int i = 0; i < n; i++){
        ll y = alturas[i]; 
        if (y < x){
            i_menor = i;
            break;
        } 
    }
    int diff = x - alturas[i_menor];

    for(int i = i_menor; i <i_menor +k; i++){
        if(i >= n) break;
        if(diff > k) {
            break;
        }
        alturas[i] += diff; 
        // if ( alturas[i] < x){
        //     cerr  << alturas[i] << " < " << x << endl;
        //     return false;
        // } 
        diff ++;
    }

    for(ll u : alturas){
        if(u < x){
            // cerr  << u << " < " << x << endl;
            // for(ll u : alturas) cerr << u << " ";
            return false;
 
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 



    cin >> n >> k;

    vector<ll> alturas(n);

    for( int i = 0; i < n; i++){
        cin >> alturas[i];    
    }

    ll l = 0;
    // ll r = 2e9;
    ll r = 20;

    ll resp;
    while(l<=r){
        ll mid = l + (r-l)/2;
        // cerr << "Mid: " << mid << " | " << check(mid, alturas) << endl;
        if(check(mid, alturas)){
            resp = mid;
            l = mid +1;
        }
        else{
            r = mid-1;
        }

    }

        cout << resp << endl;
    
    return 0;

}
