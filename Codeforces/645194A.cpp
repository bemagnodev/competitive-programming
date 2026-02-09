#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
#define pb push_back
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;  
const int INF = 2e9;
const ll INFLL = 4e18;

 
struct Node {
    int sum;       
    int min_pref; 
    int max_pref;  
};

struct SegTree {
    int n;
    vector<Node> tree;
    vector<bool> lazy;  
    Node neutro = {0, 0, 0};

    Node merge(Node a, Node b) {
        Node ans;
        ans.sum = a.sum + b.sum;
        ans.min_pref = min(a.min_pref, a.sum + b.min_pref);
        ans.max_pref = max(a.max_pref, a.sum + b.max_pref);
        return ans;
    }

    SegTree(const string& s) {
        n = s.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, false);  
        build(s, 1, 0, n - 1);
    }

    void build(const string& s, int i, int tl, int tr) {
        if (tl == tr) {
            if (s[tl] == '(') {
                tree[i] = {1, 1, 1}; 
            } else {
                tree[i] = {-1, -1, -1};
            }
        } else {
            int tm = (tl + tr) / 2;
            build(s, 2 * i, tl, tm);
            build(s, 2 * i + 1, tm + 1, tr);
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void push(int i, int tl, int tr) {
        if (lazy[i]) {  
            int tm = (tl + tr) / 2;
            
            inverter(2 * i);
            inverter(2 * i + 1);
            
            lazy[2 * i] = !lazy[2 * i];
            lazy[2 * i + 1] = !lazy[2 * i + 1];

            lazy[i] = false;
        }
    }

    void inverter(int i) {
        tree[i].sum *= -1;  
        
        int old_min = tree[i].min_pref;
        int old_max = tree[i].max_pref;
        
        tree[i].min_pref = -old_max;
        tree[i].max_pref = -old_min;
    }

    void update(int i, int tl, int tr, int l, int r) {
        if (l > r) return;

        if (l == tl && r == tr) {
            inverter(i);
            lazy[i] = !lazy[i];
        } else {
            push(i, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * i, tl, tm, l, min(r, tm));
            update(2 * i + 1, tm + 1, tr, max(l, tm + 1), r);
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }

    Node query(int i, int tl, int tr, int l, int r) {
        if (l > r) return neutro;
        if (l == tl && r == tr) return tree[i];
        
        push(i, tl, tr);
        int tm = (tl + tr) / 2;
        
        if (r <= tm) return query(2 * i, tl, tm, l, r);
        if (l > tm) return query(2 * i + 1, tm + 1, tr, l, r);

        return merge(
            query(2 * i, tl, tm, l, min(r, tm)),
            query(2 * i + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }

    void update(int l, int r) { update(1, 0, n - 1, l, r); }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve() {
    int n, q; cin >> n >> q;
    
    string s; 
    cin >> s;
    
    SegTree st(s);

    while (q--) {
        int tp; 
        cin >> tp;
        if (tp == 1) { 
            int l, r; 
            cin >> l >> r;
            st.update(l - 1, r - 1);
        } else {  
            int l, r; 
            cin >> l >> r;
            
            Node ans = st.query(l - 1, r - 1);
            
            if (ans.sum == 0 && ans.min_pref == 0) {
                cout << "sim\n";
            } else {
                cout << "nao\n";
            }
        }
    }
}

int main() {
    fastio;
    solve();
    return 0;
}