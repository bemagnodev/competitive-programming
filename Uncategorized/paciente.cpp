#include <bits/stdc++.h>
#include <numeric>
using namespace std;
struct DSU{
    vector<int> pai;
    vector<int> tamanho;

    DSU(int n){
        pai.resize(n);
        iota(pai.begin(), pai.end(), 0);
        tamanho.assign(n,1);
    }
    int find(int i){
        if(pai[i] == i) return i;
        return pai[i] = find(pai[i]);
    }

    void uniao(int i, int j){
        int lider1 = find(i);
        int  lider2 = find(j);
        
        if (lider1 != lider2){
            if(tamanho[lider1] < tamanho[lider2]){
                swap(lider1, lider2);
            }
            pai[lider2] = lider1;
            tamanho[lider1] += tamanho[lider2];
        }
    }
};

int main(){
    int n, m; cin >> n >> m;
    DSU dsu(n);

    for (int i =0; i< m; i++){
        int k; cin >> k;
        int l; cin >> l;
        for (int i =0; i< l; i++){
            int x; cin >> x;
            dsu.uniao(k, x);
        }
    }
    set<int> paciente0;
    for( int i = 0; i < n; i++){
        paciente0.insert(dsu.find(i));
    }

    for (auto it = paciente0.begin(); it != paciente0.end(); ++it) {
       cout << *it << endl; 
    }
    
    return 0;
}