#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5+7;
vector<bool>primos(MAXN, true);

void crivo(){
    int n = MAXN;
    primos[0] = false;
    primos[1] = false;
    for(int i = 2; (ll)i*i <= n; i++){
        if(primos[i]){
            for(int j = (ll)i*i; j<=MAXN; j+=i){
                primos[j] = false;
            }
        }
    }
}

bool fato_lenta(ll x){
    if(x <=1) return false;
    for(int i = 2; (ll)i*i <= x; i++){
        if(x%i == 0) return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;

    crivo();
    vector<ll>ans;

    for(int i = 0; i < n; i++){
        int m; cin >> m;
        vector<int>array(m+1);
        
        ll soma = 0;
        for(int j = 1; j <= m; j++){
            cin >> array[j];
            if(primos[j]) soma += array[j];
        }

        if(fato_lenta(soma)) ans.push_back(soma);

    }
    if(ans.size() == 0) cout << "ITS OVER SOBROU NADA PRO BETINHA" << endl;
    else{
        cout << ans.size() << endl;

        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
    

}