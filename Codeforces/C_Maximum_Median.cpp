#include <bits/stdc++.h>

using namespace std;

bool ok( long long k, long long mid, long long n, vector<int>& a){
    long long custo_total = 0;
    long long x = mid;
    for(int i = n/2; i< n;i++){ // elementos do meio pra direita 
        if(a[i] < x){
            custo_total += x - a[i];
        }
    }
    return(custo_total <= k);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
   
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i< n; i ++) cin >> a[i];

    sort(a.begin(), a.end());

    long long low =1;
    long long high = 2e9;
    long long answer = high;

        
    while (low<= high){
        long long mid = low + (high- low) / 2;
        if(ok(k, mid, n, a)){
            answer =mid;
            low = mid + 1;
            
        }
        else{
            high = mid -1;

        }
    
    }
    cout << answer << endl;

    return 0;


}
