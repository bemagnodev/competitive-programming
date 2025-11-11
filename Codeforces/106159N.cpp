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
    ll D, Y; cin >> D >> Y;
    ll passos =0, delta = 0, ultimo_passo = 0;
    while(delta <= D){
        if(passos ==0){
            delta +=1;
        }
        else{
            delta += (1LL << passos-1)* 3;
        }
        
        //  cerr << delta << " ";
        cerr << delta +(1LL << passos)* 3 << " >= " << D << endl;
        if(delta +((1LL << passos)* 3) >= D){
            ultimo_passo= D - delta;
            passos++;
            cerr << passos << endl;
             cerr<< endl << "up: "<< ultimo_passo << endl;
            break;
        }
        passos++;
    }

    
    
    //simular a partir de y
    ll X_candidato = 0;
    if(passos%2==0){
        X_candidato = Y + (1LL << passos -1) - ultimo_passo; // 2^passos
    }
    else{
        X_candidato = Y - (1LL << passos-1) + ultimo_passo; // 2^passos
    }
    cerr << X_candidato ;

    //buscar limites de exploração dos passos primeiros passos
    ll atual = X_candidato;
    ll l= atual, r = atual;
    FOR(i,0,passos){
        if(i%2==0){//soma
            atual = X_candidato + (1LL << i);
            
        }else{
            atual = X_candidato - (1LL << i);
        }
        l= min(l, atual);
        r= max(r, atual);
        // cerr << l << " - " << r << endl;
    }
    
    if( Y > r || Y < l){
       cout << "Sim\n" << X_candidato << endl;
       return; 
    }
    if(ultimo_passo == 0){
        cout << "Sim\n" << X_candidato << endl;
    } else {
        cout << "Nao" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    // cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}
