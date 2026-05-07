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

void dfs(int node, vector<vector<int>>& adj, vector<bool> &visited){
    visited[node] = true;
    cout << node << " ";
    for(auto e : adj[node]){
        if(!visited[e]){
            dfs(e, adj, visited);
        }
    }
}

int main(){
    optimize();
    // n -> number of nodes
    // m -> number of edges
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // considering the graph to be undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   

    vector<bool> visited(n + 1, false);
    dfs(1, adj, visited);

    return 0;
}