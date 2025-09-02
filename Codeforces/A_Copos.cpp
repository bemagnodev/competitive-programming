#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n; cin >>n;
    int resp = 2e6;

    for (int a = 1; a*a*a <=n; a++){
        // cerr << "a: " << a << endl;
        if(n % a == 0){
            // cerr << "a: " << a << endl;
            for (int b = a; b <= n; b++){
                if((n/a)%b==0){
                    int c = n /(a*b);
                    // cerr << "b: " << b << endl;
                    // cerr << "c: " << c << endl;

                    if(c < b) break;
                    int s =2*(a*b +a*c+b*c);
                    resp = min(resp, s);
                }
            }
            
        }
    }

    cout << resp << endl;




    return 0;
}