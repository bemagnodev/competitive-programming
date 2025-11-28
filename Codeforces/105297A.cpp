#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n; cin >>n;

    vector<vi> convidados(n, vi(4)); // momento, duração, skip? , id

    FOR(i,0,n){
        int t, d, c; cin >> t >> d >> c;
        convidados[i] = {t,d,c,i+1};
    }

    sort(all(convidados));

    queue<vi> q;
    vi tristes;

    int id_tocando = -1; ll acaba = 0;

    FOR(i,0,n){
        int momento = convidados[i][0];
        int duracao = convidados[i][1];
        int skip = convidados[i][2];
        int id = convidados[i][3];
        
        while(id_tocando != -1 && momento >= acaba){
            if(!q.empty()){
                vi prox = q.front();
                q.pop();
                id_tocando = prox[3];
                acaba = acaba + prox[1];
            }
            else{
                id_tocando = -1;
            }
        }
        //se tem algo tocando e deu-se skip
        if(id_tocando == -1){
            id_tocando = id;
            acaba = (ll)momento + duracao;
        }
        else{
            if(skip){
                tristes.push_back(id_tocando);
                id_tocando = id;
                acaba = (ll)momento + duracao;
            }
            else{
                q.push(convidados[i]);
            }
        }
    }

    cout << tristes.size() << endl;
    
    FOR(i,0,tristes.size()) cout << tristes[i] << " "; cout << endl;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
