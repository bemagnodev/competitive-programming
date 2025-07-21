#include <bits/stdc++.h>

using namespace std;

bool ok( long long k, long long mid, long long n){
    long long numeros_nao_divisiveis_por_n = mid - mid/n;
    return(numeros_nao_divisiveis_por_n >= k);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;

        long long low =1;
        long long high = 2e10;
        long long answer = high;

         
        while (low<= high){
            long long mid = low + (high- low) / 2;
            if(ok(k, mid, n)){
                answer =mid;
                high = mid -1;

            }
            else{
                low = mid + 1;

            }
        }
        
    
        
    
    
        cout << answer << endl;
    }

    return 0;


}
