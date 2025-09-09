#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t; cin >> t;

    vector<int> dp_primos(1e6 + 5, 0);

    for(int i = 2; i<1e6 + 5; i++){
        if(is_prime(i)){
            dp_primos[i] = dp_primos[i-1] + 1;
        }
        else{
            dp_primos[i] = dp_primos[i-1];
        }
    }

    while(t--){
            int i, j; cin >> i >>j;
            cout << dp_primos[j] - dp_primos[i-1] << '\n';    
    }
}