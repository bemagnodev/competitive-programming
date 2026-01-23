#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define mii map<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (int)(x).size()
#define ins insert
#define deb(k) cerr << #k << ": " << k << "\n";
typedef vector<int> vi;
typedef vector<ll> vll;


void solve(){
    int n; cin >> n;
    vll a(2*n), b(2*n), pref(2*n+1, 0);
    FOR(i,0,n) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    FOR(i,0,2*n){
        pref[i+1] = a[i]+ pref[i];
    }

    
    FOR(i,0,n) {
        cin >> b[i];
        b[i+n] = b[i];

    }
    int k, l; cin >> k >> l;

    multiset<ll> dentro, resto;

    ll soma_b = 0;
    FOR(i,0,k){
        dentro.insert(b[i]);
        soma_b +=b[i];

        if((int)dentro.size() > l){
            ll menor = *dentro.begin(); 
            dentro.erase(dentro.begin());
            soma_b-=menor;
            resto.insert(menor);
        }
    }
    ll soma_a = pref[k] - pref[0];
    ll mx = soma_a+soma_b;

    FOR(i,1, n+1){
        
        int j =i+k-1;
        
        ll saiu = b[i-1];
        ll entrou = b[j];

        bool estava_dentro = (dentro.find(saiu) != dentro.end());

        // saiu
        if(estava_dentro){
            auto it = dentro.find(saiu);
            dentro.erase(it);
            soma_b -= saiu;

            if(!resto.empty()){
                ll maior_resto = *resto.rbegin();
                resto.erase(prev(resto.end()));
                dentro.insert(maior_resto);
                soma_b += maior_resto;
            }
        }else{
            auto it = resto.find(saiu);
            if(it != resto.end()){
                resto.erase(it);
            }
        }

        //entrou
        dentro.insert(entrou);
        soma_b +=entrou;
        
        if((int)dentro.size() > l){
            ll remover = *dentro.begin();
            soma_b-= remover;
            dentro.erase(dentro.begin());
            resto.insert(remover);
        }
         
        
        ll valA = pref[i+k]- pref[i];
        
        if(i < n && !(i > 0 && i + k <= n)){
            mx = max(mx, soma_b+valA);
        }
        

    }


    cout << mx << endl;//
    
     
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}

