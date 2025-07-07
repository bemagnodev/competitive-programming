#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n; cin >> n;
    int l; cin >> l;

    vector<int> lanternas(n);

    for (int i = 0; i <n ; i++){
        int lanterna; cin >> lanterna; 
        lanternas[i] = lanterna;
        // cout << lanternas[i] << " ";
    }
    
    //ordenar vetor de lanternas
    sort(lanternas.begin(), lanternas.end());
    double dist_inicio = lanternas[0];
    double dist_final = l -  lanternas[n-1];
    double dist_meio = 0;

    for (int i = 0; i <n-1 ; i++){

        if(lanternas[i+1]- lanternas[i] > dist_meio){
            dist_meio = (lanternas[i+1]- lanternas[i]);
        }
    }
    dist_meio = dist_meio/2;

    double d = max(dist_meio, max(dist_final, dist_inicio));
    // cout << endl << dist_inicio <<" "  << dist_meio << " "<< dist_final << endl;
    cout << fixed << setprecision(10) << d << endl;
    return 0;


}
