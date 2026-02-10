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

struct SegTree {
    int n;
    vi tree;
    
    SegTree(int size) {
        n = 1;
        while(n < size) n *= 2; 
        tree.assign(2 * n, 0);
    }

    void update(int p, int value) {
        p += n;
        tree[p] += value;  
        for (; p > 1; p >>= 1) {
            tree[p >> 1] = tree[p] + tree[p ^ 1];
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

struct Reta {
    ll y1, y2;  
    int id;
};

void solve() {
    int n; 
    ll x1, x2;
    cin >> n >> x1 >> x2;

    vector<Reta> retas(n);
    vector<ll> coords;  

    FOR(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        retas[i].y1 = a * x1 + b;
        retas[i].y2 = a * x2 + b;
        retas[i].id = i;
        coords.push_back(retas[i].y2);
    }

    sort(all(retas), [](const Reta& a, const Reta& b) {
        if (a.y1 != b.y1) return a.y1 < b.y1;  
        
        return a.y2 > b.y2; 
    });

    sort(all(coords));
    coords.erase(unique(all(coords)), coords.end()); 

    auto get_rank = [&](ll val) {
        return lower_bound(all(coords), val) - coords.begin();
    };

    int m = coords.size();
    SegTree st(m); 
    
    ll ans = 0;

    for (auto& l : retas) {
        int rank_y2 = get_rank(l.y2);
        ans += st.query(rank_y2, m);
        st.update(rank_y2, 1);
    }

    cout << ans << "\n";
}

int main() {
    fastio;
    solve();
    return 0;
}