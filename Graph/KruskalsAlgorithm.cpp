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


// TC: O(1)
class DSU{
    vector<int> parent, size, rank;
public:
    DSU(int n){
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }    
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]); // Path compression
    }
    
    void unionBySize(int u, int v){
        u = findParent(u); // Ultimate Parent of u in it's set
        v = findParent(v); // Ultimate Parent of v in it's set
        
        // Both are from same set
        if(u == v){
            return;
        }

        // Connect Smaller to the Bigger set
        if(size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }else{
            parent[v] = u;
            size[u] += size[v];
        }
    }

    void unionByRank(int u, int v){
        u = findParent(u); // Ultimate Parent of u in it's set
        v = findParent(v); // Ultimate Parent of v in it's set
        
        // They are from same set
        if(u == v){
            return;
        }

        // Connect smaller rank to higher rank
        if(rank[u] == rank[v]){
            parent[v] = u;
            rank[u]++;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[u] = v;
        }
    }
};

int main(){
    optimize();
    int n, m;
    cin >> n >> m;
    vector<pair<ll, pair<int,int>>> edges;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    // Sort all the edges based on their weights
    sort(edges.begin(), edges.end());

    
    DSU dsu(n); // Use Union Find Data Structure to detect cycle
    ll sum = 0;
    int edgeCnt = 0;

    // TC: O(n)
    for(auto [w,uv] : edges){
        auto [u,v] = uv;
        // If not forming cycle connect edges
        if(dsu.findParent(u) != dsu.findParent(v)){
            sum += w;
            dsu.unionByRank(u, v);
            if(edgeCnt <= n - 1){
                edgeCnt++;
            }else{
                break;
            }
        }
    }
    if(edgeCnt == n - 1){
        cout << sum << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

// Problem : Road Reparation (https://cses.fi/problemset/task/1675/)