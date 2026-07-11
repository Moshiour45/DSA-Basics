# include<bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'


class DSU{
    vector<int> parent,rank;
    int n;
public:
    DSU(int n){
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int node){
        return parent[node] = ((parent[node] == node) ? node : find(parent[node]));
    }
    void unionByRank(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v){
            return;
        }
        if(rank[u] == rank[v]){
            parent[v] = u;
            rank[u]++;
        }else if(rank[u] < rank[v]){
            parent[u] = v;
        }else{
            parent[v] = u;
        }
    }

    void connectingParent(int u, int v){
        parent[u] = v;
    }
};


int main(){
    optimize();
    int n, q;
    cin >> n >> q;
    vector<ll> v(n + 1, 0);
    vector<pair<ll, pair<int,int>>> query(q); // Offline Query
    while(q--){
        int l, r;
        ll val;
        cin >> l >> r >> val;
        query[q] = {val,{l,r}};
    }

    DSU dsu(n + 123);

    // Traverse from last query to first and connect one node to the next node if the node is pointing to itself
    for(auto [val, u] : query){
        auto [l,r] = u;
        for(int i = l; i <= r; i++){
            int parent = dsu.find(i);
            if(parent > r){
                break;
            }
            if(parent == i){
                dsu.connectingParent(i, i + 1);
                v[i] = val;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << v[i] << endl;
    }
    return 0;
}
// Problem : COLORFUL ARRAY(https://www.spoj.com/problems/CLFLARR/)