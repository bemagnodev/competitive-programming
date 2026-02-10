    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;

    int main() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 


        ll n; cin >> n;
        vector<int> alturas(n+1);
        vector<int> a_mais_i(n+1);
        vector<int> a_menos_i(n+1);

        for( int i = 1; i <= n; i++){
            cin >> alturas[i];
            a_mais_i[i] = alturas[i]+i;
            a_menos_i[i] = alturas[i]-i;
        }

        sort(a_mais_i.rbegin(), a_mais_i.rend());
        sort(a_menos_i.rbegin(), a_menos_i.rend());

        int resposta = a_mais_i[0]+a_menos_i[0];
        assert(resposta  == 63);
        cout <<resposta<< endl;
        cerr << "hahaha" << endl;
        
        return 0;

    }
