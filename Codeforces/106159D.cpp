#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> computeLPS(const vector<int>& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // Comprimento do prefixo/sufixo anterior

    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1];
        }
        if (pattern[i] == pattern[len]) {
            len++;
        }
        lps[i] = len;
    }
    return lps;
}


vector<int> KMPSearch(const vector<int>& text, const vector<int>& pattern) {
    int n = text.size();
    int m = pattern.size();
    
     
    if (m == 0) return {};

    vector<int> lps = computeLPS(pattern);  
    vector<int> matches; 

    int i = 0; 
    int j = 0;  

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            matches.push_back(i - j);  
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<int> DA(n - 1);
    for (int i = 0; i < n - 1; i++) {
        DA[i] = (A[i + 1] - A[i] + 10000) % 10000;
    }

    vector<int> DB(m - 1);
    for (int i = 0; i < m - 1; i++) {
        // (B[i+1] - B[i]) com módulo 10000
        DB[i] = (B[i + 1] - B[i] + 10000) % 10000;
    }

     
    vector<int> matches = KMPSearch(DA, DB);

    
    vector<int> shift_counts(10000, 0);

    for (int start_index : matches) {
         
        
        int k = (B[0] - A[start_index] + 10000) % 10000;
        
        shift_counts[k]++;
    }

    
    int best_shift = 0;
    int max_ocorrencias = 0;

    for (int k = 0; k < 10000; k++) {
        if (shift_counts[k] > max_ocorrencias) {
            max_ocorrencias = shift_counts[k];
            best_shift = k;
        }
    }

    cout << best_shift << " " << max_ocorrencias << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}